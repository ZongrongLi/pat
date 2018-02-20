
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
#include<stack>
using namespace std;
int n = 0,h,k;
class node {
public:
	int ad;
	int d;
	int next;
};
node A[100200];
queue<node> q;
stack<node>st;
vector<node>vt;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d",&h, &n,&k);
	for (int i = 0; i < n; i++) {
		node t;
		int ad;
		scanf("%d %d %d",&t.ad,&t.d,&t.next);
		A[t.ad] = t;
	}
	int p = h;
	while (p!=-1)
	{
		q.push(A[p]);
		p = A[p].next;
	}
	while (q.size() >= k)
	{
		int c = k;
		if(q.size() >= k)
		while (c--)
		{
			st.push(q.front());
			q.pop();
		}
		while (!st.empty())
		{
			vt.push_back(st.top());
			st.pop();
		}
		
	}
	while (!q.empty())
	{
		vt.push_back(q.front());
		q.pop();
	}
	for (int i = 0; i < vt.size(); i++) {
		if(i!=vt.size()-1)
		printf("%05d %d %05d\n",vt[i].ad,vt[i].d,vt[i+1].ad);
		else 
			printf("%05d %d -1\n", vt[i].ad, vt[i].d);
	}
	//printf();

	return 0;
}
