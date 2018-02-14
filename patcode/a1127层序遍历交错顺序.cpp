
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int n = 0;
int in[50] = { 0 };
int post[50] = { 0 };
class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		l = r = NULL;
		d = 0;
	}
};
pair<int, int> intopost(int l, int r) {
	int Min = 65535;
	int Max = -1;
	for (int i = 0; i < n; i++) 
		for (int  j= l; j <= r; j++) {
			if (in[j] == post[i]) {
				Min = Min < i ? Min : i;
				Max = Max > i ? Max : i;
		}
	}
	return make_pair(Min, Max);
}
node *root = NULL;
void dfs(node *&t,int il,int ir, int pl,int pr) {
	if (il > ir || pl > pr)return;
	t = new node;
	t->d = post[pr];
	if (il == ir || pl == pr)return;
	int idx = -1;
	for(int i=0;i<n;i++)
		if (in[i] == t->d) {
			idx = i;
			break;
		}
	pair<int, int> pt = intopost(il, idx - 1);
	dfs(t->l,il, idx - 1, pt.first, pt.second);

	 pt = intopost(idx+1, ir);
	dfs(t->r, idx+1, ir, pt.first, pt.second);
}

deque<node*> q;
vector<int>ans;
void levelorder(node *root) {
	q.push_back(root);
	int last = root->d;
	int flag = 1;;
	ans.push_back(root->d);
	while (!q.empty())
	{
		node* t = q.front();
		q.pop_front();
		
		if (t->l != NULL)q.push_back(t->l);
		if (t->r != NULL)q.push_back(t->r);
		

		if (q.empty())break;
		//ans.push_back(t->d);
		if (t->d == last) {
			last = q.back()->d;
			if (flag == 1) {
				int c = q.size();
				while (c--) {
					node *t = q.front();
					ans.push_back(t->d);
					q.pop_front();
					q.push_back(t);
				}
			}
			if (flag == -1) {
				int c = q.size();
				while (c--) {
					node *t = q.back();
					ans.push_back(t->d);
					q.pop_back();
					q.push_front(t);
				}
			}
			flag *= -1;
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&in[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}

	//printf();
	
	dfs(root, 0, n - 1,0,n-1);
	levelorder(root);
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)printf("%d ",ans[i]);
		else printf("%d", ans[i]);
	}
	return 0;
}
