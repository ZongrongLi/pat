
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int a[1010];
class node {
public:
	int data;
	node *left;
	node *right;
};

node *root;
void insertB(int k) {
	
	if (root == NULL) {
		root = new node;
		root->data = k;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	node *p = root;
	node *pre = p;
	int flag = -1;
	while (p!=NULL)
	{
		pre = p;
		if (k >= p->data) {
			p = p->right;
			flag = 1;
		}
		else {
			p = p->left;
			flag = 2;
		}
	}
	p = new node;
	p->left = NULL;
	p->right = NULL;
	p->data = k;
	if (flag == 1)pre->right = p;
	else pre->left = p;

}

void tranverse(node *root) {
	if (root == NULL)return;
	tranverse(root->left);
	tranverse(root->right);
	node * tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}





int cnt = 0;
int  n;
void postorder(node *root) {
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	if(cnt!=n-1)
	printf("%d ",root->data);
	else
		printf("%d", root->data);
	cnt++;
}
int pre[1010];
int pretop = -1;

void preoder(node *root) {
	if (root == NULL)return;
	
	pre[++pretop] = root->data;
	preoder(root->left);
	preoder(root->right);
}


int main() {
	freopen("./test.txt", "r", stdin);
	n = 0;
	scanf("%d", &n);
	root = NULL;
	for (int i = 0; i < n; i++) {
		
		scanf("%d", &a[i]);
		insertB(a[i]);
	}


	memset(pre, 0, 1010);
	preoder(root);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (a[i] != pre[i]) {
			flag = true;
			break;
		}
	}
	if (flag) {
		tranverse(root);
		memset(pre, 0, 1010);
		pretop = -1;
		preoder(root);
		flag = false;
		for (int i = 0; i < n; i++) {
			if (a[i] != pre[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			printf("NO");
		}
		else {
			printf("YES\n");
			postorder(root);
		}

	}
	else {
		printf("YES\n");
		postorder(root);
	}

	return 0;
}
