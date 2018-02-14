
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
int pre[50] = {0};
int post[50] = { 0 };

class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};
bool flag = false;
vector<int>ans;
void create(node *&t,int prel, int prer, int pol, int por) {
	if (prel > prer || pol > por)return;
	t = new node;
	t->d = pre[prel];
	if (prel == prer) {
		ans.push_back(t->d);
		return;
	}
	int tmp = post[por-1];
	int idx;
	for (int i = prel; i <= prer; i++) {
		if (pre[i] == tmp) {
			idx = i;
			break;
		}
	}

	int len1 = idx - prel-1;
	//cout << "--" << len1 << endl;
	int len2 = prer - idx;
	if (len1 > 0)
		create(t->l, prel + 1, prel + len1, pol, pol + len1 - 1);
	else
		flag = true;
	ans.push_back(t->d);
	create(t->r, idx, prer, pol+len1, por-1);
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	//printf();
	node *root = NULL;
	create(root, 0, n - 1,0,n-1);
	if (!flag)printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)printf("%d ",ans[i]);
		else printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}