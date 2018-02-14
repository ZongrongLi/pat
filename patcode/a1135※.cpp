
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
	node *l;
	node *r;
	node(){
		l = r = NULL;
	}
};
node *root=NULL;
void freetree(node *&t) {
	if (t == NULL)return;
	else if (t->l == NULL && t->r == NULL) {
		delete t;
		t = NULL;
		return;
	}
	else if (t->l != NULL)freetree(t->l);
	else if (t->r != NULL)freetree(t->r);
	freetree(t);
}
void insert(node *&t,int k) {
	if (t == NULL) {
		t = new node;
		t->d = k;
		return;
	}
	if (abs(k) <= abs(t->d))insert(t->l, k);
	else insert(t->r, k);
}
bool br(node* t) {//ºì»¹ÊÇºÚ
	if (t == NULL)return true;
	if (t->d > 0)return true;
	return false;
}
bool judge1(node *t) {
	if (t == NULL)return true;
	bool flag = false;
	if (t->d < 0) {
		if (br(t->l) && br(t->r))flag = true;
		else return false;
	}
	else flag = true;
	return judge1(t->l) && judge1(t->r) && flag;
}

int judge2(node *t) {
	if (t == NULL) return 1;
	int l = judge2(t->l);
	int r = judge2(t->r);
	if (l == -1 || r == -1)return -1;
	if (l != r) return -1;
	if (t->d > 0)return max(l, r) + 1;
	else return max(l, r);
}

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int  m;
		scanf("%d",&m);
		freetree(root);
		root = NULL;
		for (int j = 0; j < m; j++) {
			int t;
			scanf("%d",&t);
			insert(root,t);
		}
		if (root->d < 0) {
			printf("No\n");
			continue;
		}
		if (judge1(root)&&(judge2(root)!=-1))printf("Yes\n");
		else printf("No\n");
	}
	//printf();

	return 0;
}

