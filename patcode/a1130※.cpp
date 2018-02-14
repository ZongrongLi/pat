
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
	int id;
	char d[20];
	int il;
	int ir;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};
vector<node>vt;
int v[1000] = { 0 };
node *root = NULL;
void create(node *&t,int it) {
	if (it == -1)return;
		t = new node;
		strcpy( t->d ,vt[it].d);
		create(t->l,vt[it].il);
		create(t->r, vt[it].ir);
}
//vector<char>ans;

void inorder(node *t,int d) {
	if(t == NULL)return;
	if(d!=0)
	if (!(t->l == NULL && t->r == NULL)) {
		printf("%c", '(');
	}
	if (t->l != NULL)inorder(t->l,d+1);
		printf("%s",t->d);
	if (t->r != NULL)inorder(t->r,d+1);
	if(d!=0)
	if (!(t->l == NULL && t->r == NULL))
		printf("%c",')');
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d\n", &n);
	vt.resize(n + 5);
	for (int i = 1; i <= n; i++) {
		node t;
		scanf("%s %d %d\n",&t.d,&t.il,&t.ir);
		t.id = i;
		vt[i] =t;
		v[t.il] = v[t.ir]=1;
	}
	int iroot = 0;
	for(int i=1;i<=n;i++)
		if (v[i] == 0) {
			iroot = i;
			break;
		}

	create(root,iroot);
	inorder(root,0);

	return 0;
}
