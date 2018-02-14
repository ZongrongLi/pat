
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
	int add;
	int data;
	int next;
	node *nextp;
	node() {
		add = 0;
		data = 0;
		next = 0;
		nextp = NULL;
	}
};
vector<node>A;
node* st[100200];
int top = -1;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,first,k;
	scanf("%d %d %d", &first,&n,&k);
	if (first == -1) {
		printf("-1");
		return 0;
	}
	A.resize(100200);
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %d %d",&t.add,&t.data,&t.next);
		A[t.add] = t;
	}

	node * head = new node;
	node *p = head;
	p->next = first;
	while (p->next!=-1)
	{
		node *t = new node;
		(*t) = A[p->next];
		p->nextp = t;
		p = p->nextp;
	}
	p = head->nextp;
	node *head1 = new node;
	node *cur = head1;
	while (p!=NULL)
	{
		st[++top] = p;
		p = p->nextp;
		if (top+1 == k) {
			while (top!=-1)
			{
				cur->nextp = st[top];
				cur = cur->nextp;
				top--;
			}
		}

		
	}
	if (top != -1) {
		for(int i=0;i<=top;i++)
		{
			cur->nextp = st[i];
			cur = cur->nextp;
		}
	}
	cur->nextp = NULL;
	cur->next = -1;
	p = head1->nextp;
	while (p!=NULL)
	{
		if(p->nextp!=NULL)
			printf("%05d %d %05d\n",p->add,p->data,p->nextp->add);
		else 
			printf("%05d %d -1\n",p->add,p->data);
		p = p->nextp;
	}
	//printf();

	return 0;
}