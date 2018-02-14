
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
class node {
public:
	int d;
	int h;
	node *l;
	node *r;
	node() {
		l = r = NULL;
		h = 1;
	}
};
int geth(node *t) {
	if (t == NULL)return 0;
	return t->h;
}
void updateH(node *t) {
	if (t == NULL)return;
	 t->h =max(geth(t->l), geth(t->r)) + 1;
}
void LL(node *&t) {
	node *tmp = t->r;
	t->r = tmp->l;
	tmp->l = t;
	updateH(t);//////////////////////----------先下在上
	updateH(tmp);
	t = tmp;
}
void RR(node *&t) {
	node *tmp = t->l;
	t->l = tmp->r;
	tmp->r = t;
	updateH(t);
	updateH(tmp);
	t = tmp;
}
int getfactor(node *t) {
	if (t == NULL)return 0;
	return geth(t->l) - geth(t->r);
}
void insertN(node *&root,int k) {
	if (root == NULL) {
		root = new node;
		root->d = k;
		return;
	}
	if (k<root->d) {
		insertN(root->l, k);
		updateH(root);
		if (geth(root->l) - geth(root->r) == 2) {
			if(getfactor(root->l) == 1)
				RR(root);
			else if (getfactor(root->l) == -1) {
				LL(root->l);
				RR(root);
			}
		}		
	}
	else {
		insertN(root->r, k);
		updateH(root);
		if (geth(root->l) - geth(root->r) == -2) {
			if (getfactor(root->r) == 1) {
				RR(root->r);
				LL(root);
			}
			else if (getfactor(root->r) == -1) {
				LL(root);
			}
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	node *root=NULL;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		insertN(root, t);
	}
	printf("%d",root->d);

	return 0;
}

