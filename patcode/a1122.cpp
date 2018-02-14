
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
int A[300][300];
int v[300];
bool iscy(vector<int>&t) {
	memset(v, 0, sizeof(v));
	if (t[0] != t[t.size() - 1])return false;
	v[t[0]] = 1;
	for (int i = 1; i < t.size(); i++) {
		if (i != t.size() - 1 && t[i] == t[0])return false;
		if (A[t[i - 1]][t[i]] == 0)return false;
		v[t[i]] = 1;
	}
	for (int i = 1; i <= n; i++)if (v[i] == 0)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 300 * 300, 0);
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		A[a][b] = A[b][a] = 1;
	}
	int c;
	scanf("%d", &c);

	for (int i = 1; i <= c; i++) {
		int t;
		vector<int>tmp;
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			int tt;
			scanf("%d",&tt);
			tmp.push_back(tt);	
		}
		if (iscy(tmp))printf("YES\n");
		else printf("NO\n");
	}
	//printf();

	return 0;
}
