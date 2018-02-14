
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
int n = 0,m;
vector< vector<int> >vt;

int v[2000] = { 0 };
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	for (int i = 0; i < vt[k].size(); i++)
		dfs(vt[k][i]);
}
bool iscon() {
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0)return false;
	}
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	vt.resize(n+5);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i !=n)printf("%d ",vt[i].size());
		else printf("%d\n", vt[i].size());
		if (vt[i].size() % 2 == 1)cnt++;
	}
	dfs(1);
	if (iscon()) {
		if(cnt==0)
			printf("Eulerian");
		else if(cnt ==2)
			printf("Semi-Eulerian");
		else 
			printf("Non-Eulerian");
		return 0;
	}
	printf("Non-Eulerian");
	//printf();

	return 0;
}
