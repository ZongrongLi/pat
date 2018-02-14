
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
		int il;
		int ir;
		node() {
			l = r = NULL;
			il = ir =-1;
		}
};
node A[20];
int v[20] = {0};
vector<int>leverans;
vector<int>inans;
queue<node*>q;
void levelorder(node* root) {
	if (root == NULL)return;
	q.push(root);
	while (!q.empty())
	{
		node *t = q.front();
		q.pop();
		leverans.push_back(t->d);
		if (t->r != NULL)q.push(t->r);
		if (t->l != NULL)q.push(t->l);
		
	}
}

void inorder(node *root) {
	if (root == NULL)return;
	inorder(root->r);
	inans.push_back(root->d);
	inorder(root->l);
}

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char a, b;
		scanf("%c %c\n",&a,&b);
		A[i].d = i;
		if (a != '-') {
			A[i].il = a - '0';
			v[a - '0'] = 1;
		}
		if (b != '-') {
			A[i].ir = b - '0';
			v[b - '0'] = 1;
		}
	}
	node *root;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0)root = &A[i];
		if(A[i].il!=-1)
			A[i].l = &A[A[i].il];
		if(A[i].ir!=-1)
			A[i].r = &A[A[i].ir];
	}
	
	levelorder(root);
	inorder(root);
	for (int i = 0; i < n; i++){
		if (i != n - 1)printf("%d ",leverans[i]);
		else printf("%d", leverans[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		if (i != n - 1)printf("%d ", inans[i]);
		else printf("%d", inans[i]);
	}
	return 0;
}
