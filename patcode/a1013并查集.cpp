
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

int n, m, k;
int A[1200][1200];
int B[1200];

int getroot(int t) {
	int a = t;
	while (t != B[t])t = B[t];
	while (a!=B[a])
	{
		int z = a;
		a = B[a];
		B[z] = t;
	}
	return t;
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, 0, sizeof(A));
	scanf("%d %d %d", &n,&m,&k);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		A[a][b] = 1;
		A[b][a] = 1;
	}
	int tmp1[1200] = { 0 };
	int tmp2[1200] = { 0 };
	for (int i = 1; i <= k; i++) {
		int t;
		scanf("%d",&t);
		for (int j = 1; j <= n; j++) {
			tmp1[j] = A[t][j];
			tmp2[j] = A[j][t];
			A[t][j] = A[j][t] = 0;
		}
		for (int j = 1; j<= n; j++)B[j] = j;
		for (int u = 1; u <= n; u++) {
			if (u == t)continue;
			for (int v = 1; v <= n; v++) {
				if (v==t||u == v || A[u][v] == 0 || A[v][u] == 0)continue;
				int a = getroot(u);
				int b = getroot(v);
				if (a != b)B[a] = b;
			}
		}
		int cnt = 0;
		int visit[1200] = { 0 };
		for (int j = 1; j <= n; j++) {
			if (j == t)continue;
			visit[getroot(j)] = 1;
		}
		for (int j = 1; j <= n; j++) {
			if (j == t)continue;
			if (visit[j] == 1)cnt++;
		}
		if(cnt>0)
			printf("%d\n",cnt-1);
		else 
			printf("0\n");
		for (int j = 1; j <= n; j++) {
			A[t][j] = tmp1[j];
			A[j][t] = tmp2[j];
		}
	}
	//printf();

	return 0;
}
