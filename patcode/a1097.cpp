
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
	node * nextp;
	node() {
		nextp = NULL;
		add = 0;
		data = 0;
		next = 0;
	}
};
vector<node>reovelist;
node A[100200] ;
int v[100200] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,head;
	scanf("%d %d", &head,&n);
	if (head == -1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %d %d", &t.add, &t.data, &t.next);
		A[t.add] = t;
	}
	node *h =new node;
	h->next = head;
	node * p = h;
	while (p->next!=-1)
	{
		node *t = new node;
		(*t) = A[p->next];
		p->nextp = t;
		p = t;
	}
	p = h->nextp;
	node *pre = h;
	while (p!=NULL)
	{
		if (v[abs(p->data)] == 1) {
			reovelist.push_back(*p);
			pre->nextp = p->nextp;
			//pre = p;
			p = p->nextp;
			
			continue;
		}
		v[abs(p->data)] = 1;
		pre = p;
		p = p->nextp;
	}
	pre->next = -1;
	p = h->nextp;
	while (p!=NULL)
	{
		if (p->next != -1)
			printf("%05d %d %05d\n",p->add,p->data,p->nextp->add);
		else 
			printf("%05d %d -1\n", p->add, p->data);
		p = p->nextp;
	}

	for (int i = 0; i < reovelist.size(); i++) {
		if(i!= reovelist.size()-1)
			printf("%05d %d %05d\n", reovelist[i].add, reovelist[i].data, reovelist[i+1].add);
		else 
			printf("%05d %d -1\n", reovelist[i].add, reovelist[i].data);
	}


	return 0;
}