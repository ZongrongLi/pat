
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
int A[1200][1200];
int v[1200] = {0};
int n, m, k;
void dfs(int t) {
	if (v[t] == 1)return;
	v[t] = 1;
	for (int i = 1; i <= n; i++) {
		if (A[t][i] == 1 && v[i] != 1)dfs(i);
	}
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
	
	for (int i = 0; i<k; i++) {
		int t;
		scanf("%d", &t);
		int tmp1[1200];
		int tmp2[1200];
		for (int j = 1; j <= n; j++) {
			tmp1[j] = A[t][j];
			tmp2[j] = A[j][t];
			A[j][t]=A[t][j] = 0;
		}

		memset(v, 0, sizeof(v));
		int cnt = 0;
		v[t] = 1;
		for (int j = 1; j <= n; j++) {
			if (v[j] == 1)continue;
			cnt++;
			dfs(j);
		}
		if(cnt>0)
			printf("%d\n",cnt-1);
		if(cnt==0)
			printf("%d\n", 0);
		for (int j = 1; j <= n; j++) {
			A[t][j] = tmp1[j];
			A[j][t] = tmp2[j];
		}
			
	}
	//printf();

	return 0;
}
