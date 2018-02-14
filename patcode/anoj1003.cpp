
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
	int adderss;
	int data;
	int next;
	node *nextp;
	node() {
		adderss = -1;
		data = -1;
		next = -1;
		nextp = NULL;
	}
};
vector<node> A;
int visit[100210] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,head;
	A.resize(100210);
	scanf("%d %d", &n,&head);
	if (head == -1) {
		printf("0 -1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %d %d",&t.adderss,&t.data,&t.next);
		A[t.adderss] = t;
	}
	int tt = head;
	node *h = new node;
	node *cur = h;
	while (tt!=-1)
	{
		node  *p = new node;
		p->adderss = A[tt].adderss;
		p->data = A[tt].data;
		p->next = A[tt].next;
		tt = A[tt].next;
		cur->nextp = p;
		cur = p;
	}
	cur = h->nextp;
	node *pre = h;
	int cnt = 0;
	while (cur!=NULL)
	{
		if (visit[abs(cur->data)] == 1) {
			pre->nextp = cur->nextp;
			cur = cur->nextp;
			continue;
		}
		else
			cnt++;
		visit[abs(cur->data)] = 1;
		pre->next = cur->adderss;
		pre = cur;
		cur = cur->nextp;
	}
	printf("%d %05d\n",cnt,h->nextp->adderss);
	pre->next = -1;
	cur = h->nextp;
	while (cur!=NULL)
	{
		if(cur->next!=-1)
			printf("%05d %d %05d\n", cur->adderss, cur->data,cur->next);
		else
			printf("%05d %d -1\n", cur->adderss, cur->data);
		cur = cur->nextp;
	}
	return 0;
}
