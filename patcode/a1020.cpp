
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <utility>
#include<map>
#include <queue>
using namespace std;
class node {
public:
	int data;
	node * left;
	node * right;

};
int n;
int post[1000005];
int inorder[1000005];
 pair<int,int> fun1(int l,int r) {//根据中序下标得到后序的下标范围  //暴力搜索
	int max = -1;
	int min = 40;
	for (int i = l; i <= r; i++) {
		int j=0;
		for (; j < n; j++)
			if (post[j] == inorder[i])break;
		if (min > j)min = j;
		if (max < j)max = j;
	}
	return make_pair(min, max);
}

 int getroot(int l, int r) {//中序的下标
	 pair<int, int> p = fun1(l, r);
	 return post[p.second];
 }

node * fun(int left,int right) {
	node *root = new  node;
	if (left == right) {
		root->data = inorder[left];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	

		root->data = getroot(left,right);
		int i = 0;
		for (i = 0; i < n; i++)
			if (inorder[i] == root->data)break;
		if (i == left)root->left = NULL;
		else
			root->left= fun(left, i - 1);
		if (i == right)root->right = NULL;
		else
			root->right = fun(i + 1, right);
	

	return root;

	
}
void levelprint(node *p) {
	if (p == NULL)return;
	int cnt = 0;
	queue<node*> q;
	q.push(p);
	while (!q.empty()) {
		node * tp = q.front();
		q.pop();
		if (tp->left != NULL)
			q.push(tp->left);
		if (tp->right != NULL)
			q.push(tp->right);
		if (cnt != n-1)
			printf("%d ", tp->data);
		else
			printf("%d", tp->data);
		cnt++;
	}

}

void freetree(node* root) {
	if (root->left != NULL)
		freetree(root->left);
	if (root->right!= NULL)
		freetree(root->right);
	if (root->left == NULL && root->right == NULL) {
		delete root;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &inorder[i]);
	}
	node * root;
	root = fun(0, n - 1);
	//printf();
	levelprint(root);
	freetree(root);
	return 0;
}

