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
class node {
public:
	int data;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};
int H = 0;
void insert(node* &t,int k) {
	if (t == NULL) {
		t = new node;
		t->data = k;
		return;
	}
	if (k <= t->data)insert(t->l, k);
	else insert(t->r, k);
}
int a1 = 0, a2 = 0;
void dfs(node*t,int d) {
	if (t == NULL)return;
	if (d == H - 2)a1++;
	if (d == H-1)a2++;
	dfs(t->l, d + 1);
	dfs(t->r, d + 1);
}

int getheight(node *t,int d) {
	if (t == NULL) return d;
	return max(getheight(t->l,d+1), getheight(t->r,d+1));
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	if (n == 0) {
		printf("0 + 0 = 0"); return 0;
	}
	if (n == 1) {
		printf("1 + 0 = 1"); return 0;
	}
	node *root = new node;

	scanf("%d", &root->data);
	for (int i = 1; i < n; i++) {
		int t;
		scanf("%d",&t);
		insert(root, t);
	}
	 H = getheight(root,0);

	 if(H>2)
		dfs(root, 0);
	 else if(H==2) {
		 a1 = 1;
		 a2 = n - 1;
	 }
	printf("%d + %d = %d",a2,a1,a1+a2);

	return 0;
}