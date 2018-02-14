
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
int v[40] = { 0 };
int ans[40] = { 0 };
class node {
public:
	int a;
	int b;
};
vector<node>vt;
int main() {
	freopen("./test.txt", "r", stdin);
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		char s1[10], s2[10];
		scanf("%s %s\n",&s1,&s2);
		if (s1[0] != '-')t.a = atoi(s1);
		else t.a = -1;
		if (s2[0] != '-')t.b = atoi(s2);
		else t.b = -1;

		vt.push_back(t);
		v[t.b]= v[t.a] = 1;
	}
	int root;
	for(int i=0;i<n;i++)
		if (v[i] == 0) {
			root = i;
			break;
		}
	int idx = 1;
	ans[idx] = root;
	while (idx*2<=n)
	{
		ans[idx * 2] = vt[ans[idx]].a;
		ans[idx * 2 + 1] = vt[ans[idx]].b;
		idx++;
	}
	//printf();
	bool flag = false;
	for (int i = 1; i <= n; i++)
		if (ans[i] == -1) {
			flag = true;
			break;
		}
	if (!flag)
		printf("YES %d", ans[n]);
	else
		printf("NO %d",root);
	return 0;
}
