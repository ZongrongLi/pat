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
using namespace std;

int preo[100];
int ino[100];
int st[200];
int prep = 0;
int inp = 0;
int top = -1;
int n;
class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};

pair<int, int> intopre(int l,int r){
	int mini = 100;
	int maxi = -1;
	for (int i = 0; i < n; i++) 
		for (int j = l; j <= r; j++) {
			if (preo[i] == ino[j]) {
				mini = mini > i ? i : mini;
				maxi = maxi < i ? i : maxi;
			}
		}
	return make_pair(mini,maxi);
}
vector<int>ans;
void postlook(node * t) {
	if (t == NULL)return;
	postlook(t->l);
	postlook(t->r);
	//printf("%d ",t->d);
	ans.push_back(t->d);
}

node* create(int l1,int r1,int l2,int r2) {
	if (l1 > r1 || l2 > r2)return NULL;
	node * t = new node;
	t->d = preo[l1];
	if (l1 == r1||l2==r2)return t;
	int i = 0;
	for (; i < n; i++) 
		if (ino[i] == t->d)break;
	pair<int, int>pa = intopre(l2,i-1);
	t->l = create(pa.first, pa.second, l2, i - 1);
	pa = intopre(i+1, r2);
	t->r = create(pa.first, pa.second, i+1, r2);

	return t;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	int l = n * 2;
	char tmp[10];
	int t;
	for (int i = 0; i < l; i++) {
		scanf("%s", tmp);
		if (tmp[1] == 'u') {
			scanf("%d",&t);
			preo[prep++] = t;
			st[++top] = t;
		}
		else {
			ino[inp++] = st[top];
			top--;
		}
	}

	node * root = create(0, n - 1, 0, n - 1);
	postlook(root);
	//printf();
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)
			printf("%d ",ans[i]);
		else 
			printf("%d", ans[i]);
	}
	return 0;
}
