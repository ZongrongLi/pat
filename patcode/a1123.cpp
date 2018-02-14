
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
	t->h = max(geth(t->l), geth(t->r)) + 1;
}


void LL(node *&t) {
	node * p = t->r;
	t->r = p->l;
	p->l = t;
	updateH(t);
	updateH(p);
	t = p;
}

int getfactor(node*t) {
	if(t == NULL)return 0;
	return geth(t->l) - geth(t->r);
}
void RR(node *&t) {
	node * p = t->l;
	t->l = p->r;
	p->r = t;
	updateH(t);
	updateH(p);
	t = p;
}

void insert(node *&t,int k) {
	if (t == NULL) {
		t = new node;
		t->d = k;
		return;
	}
	if (k <= t->d) {
		insert(t->l, k);
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
		insert(t->r, k);
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
vector<int>ans;

queue<node*>q;
bool flag = false;
bool flag1 = true;
void lod(node *t) {
	q.push(t);
	while (!q.empty())
	{
		node *t = q.front();
		if (t->r != NULL && t->l == NULL)flag1 = false;
		if (flag) {
			if (t->l != NULL || t->r != NULL)flag1 = false;
		}
		ans.push_back(t->d);
		q.pop();
		if(t->l!=NULL)
			q.push(t->l);
		if (t->r != NULL)
			q.push(t->r);
		if (t->l == NULL || t->r == NULL)flag = true;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	node *root=NULL;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		insert(root,t);
	}
	lod(root);

	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)printf("%d ",ans[i]);
		else printf("%d",ans[i]);
	}
	cout << endl;
	
	if (flag1)printf("YES\n");
	else printf("NO\n");
	//printf();

	return 0;
}
