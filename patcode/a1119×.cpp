
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
	node() {
		l = r = NULL;
		d = 0;
	}
};
deque<int>pre;

deque<int>post;
vector<int>ans;

void inorder(node *t) {
	if (t == NULL)return;
	inorder(t->l);
	ans.push_back(t->d);
	inorder(t->r);
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		pre.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		post.push_back(a);
	}
	node *root =new node;
	root->d = pre.front();
	pre.pop_front();
	post.pop_back();
	bool flag = true;
	bool o = true;
	node * p = root;
	while (!pre.empty())
	{
		if (pre.front() == post.back()) {
			if (flag) 
				o = false;
			flag = true;
				if (p->l == NULL) {
					p->l = new node;
					p = p->l;
				}
				else {
					p->r = new node;
					p = p->r;
				}
				p->d = pre.front();
				pre.pop_front();
				post.pop_back();
		}
		else if (pre.front() == post.front()) {
			p->l = new node;
			p->l->d = pre.front();
			pre.pop_front();
			post.pop_front();
			flag = false;
		}
		else if (pre.back() == post.back()) {
			p->r = new node;
			p->r->d = pre.back();
			pre.pop_back();
			post.pop_back();
			flag = false;
		}
		else {
			o = false;
			while (!pre.empty())
			{
				p->r = new node;
				p = p->r;
				p->r->d = pre.front();
				pre.pop_front();
			}
			break;
		}
	}
	inorder(root);
	if (o)printf("Yes\n");
	else printf("No\n");

	for (int i = 0; i < ans.size(); i++)
		if(i!=ans.size()-1)
			printf("%d ",ans[i]);
		else 
			printf("%d\n", ans[i]);
	return 0;
}
