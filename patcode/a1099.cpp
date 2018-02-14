
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

int A[200] = {0};
int n = 0;
class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		d = -1;
		r =l = NULL;
	}
};
node* H[200] = {NULL};
int cnt = 0;
void inorder(node *t) {
	if (t==NULL)return;
	if (cnt >= n)return;
	inorder(t->l);
	t->d = A[cnt++];
	inorder(t->r);
}
queue<node*> q;
vector<int>ans;
void lorder(node *root) {
	q.push(root);

	while (!q.empty())
	{
		node *t = q.front();
		q.pop();
		ans.push_back(t->d);
		if(t->l!=NULL)
			q.push(t->l);
		if(t->r!=NULL)
			q.push(t->r);
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		H[i] = new node;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		if(a!=-1)
			H[i]->l = H[a];
		if(b!=-1)
			H[i]->r = H[b];
	}
	//printf();
	for (int i = 0; i < n; i++)
		scanf("%d",&A[i]);
	sort(A, A + n);
	inorder(H[0]);
	lorder(H[0]);
	for (int i = 0; i < n; i++) {
		if (i != n - 1)
			printf("%d ",ans[i]);
		else 
			printf("%d", ans[i]);
	}
	return 0;
}


