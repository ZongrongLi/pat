
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
	char data;
	int next;
	node *nextp;
	node() {
		add = 0;
		data = 0;
		next = -1;
		nextp = NULL;
	}
};
node A[100200];
int main() {
	freopen("./test.txt", "r", stdin);
	int ad1 = 0, ad2, n;
	scanf("%d %d %d", &ad1, &ad2, &n);
	if (ad1 == -1 || ad2 == -1) {
		printf("-1"); return 0;
	}
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %c %d", &t.add, &t.data, &t.next);
		A[t.add] = t;
	}

	node * h1 = new node;
	node *h2 = new  node;
	node *p = h1;
	p->next = ad1;
	int len1 = 0;
	while (p->next != -1)
	{
		node * t = new node;
		(*t) = A[p->next];
		p->nextp = t;
		p = t;
		len1++;
	}
	p = h2;
	p->next = ad2;
	int len2 = 0;
	while (p->next != -1)
	{
		node * t = new node;
		(*t) = A[p->next];
		p->nextp = t;
		p = t;
		len2++;
	}
	node *p1 = h1->nextp;
	node *p2 = h2->nextp;
	if (len1 < len2) {
		int c = len2 - len1;
		while (c--)
		{
			p2 = p2->nextp;
		}
	}
	if (len2 < len1) {
		int c = len1 - len2;
		while (c--)
		{
			p1 = p1->nextp;
		}
	}

	while (p1 != NULL)
	{
		if (p1->add==p2->add) {
			printf("%05d", p1->add);
			break;
		}
		p1 = p1->nextp;
		p2 = p2->nextp;
		if (p1->next == -1 || p2->next == -1)break;
	}
	if (p1->next == -1 || p2->next == -1
	 ||(p1->data == '\0')
	)printf("-1");;
	//printf();

	return 0;
}