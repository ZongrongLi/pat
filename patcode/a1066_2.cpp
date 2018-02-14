
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
	node *l;
	node *r;
	int h;
	node() {
		l = r = NULL;
		h = 1;
	}
};
int geth(node*t) {
	if (t == NULL)return 0;
	return t->h;
}

void updateH(node *t) {
	if (t == NULL)return;
	t->h = max(geth(t->l), geth(t->r)) + 1;
}

int getfactor(node *t) {
	if (t == NULL)return 0;
	return geth(t->l) - geth(t->r);
}

void LL(node *&t) {
	node *tmp = t->r;
	t->r = tmp->l;
	tmp->l = t;
	updateH(t);
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

void insertN(node *&t, int k) {
	if (t == NULL) {
		t = new node;
		t->d = k;
		return;
	}

	if (k < t->d) {
		insertN(t->l,k);
		updateH(t);
		if (getfactor(t) == 2) {
			if (getfactor(t->l) == 1) {
				RR(t);
			}
			else if (getfactor(t->l) == -1) {
				LL(t->l);
				RR(t);
			}
		}
	}
	else {
		insertN(t->r, k);
		updateH(t);
		if (getfactor(t) == -2) {
			if (getfactor(t->r) == 1) {
				RR(t->r);
				LL(t);
			}
			else if (getfactor(t->r) == -1) {
				LL(t);
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
