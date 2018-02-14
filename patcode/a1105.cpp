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
#include <functional>
using namespace std;
int n = 0,m,N;
#define MAXN 3000
int A[100200] = { 0 };
bool v[MAXN][MAXN] = { 0 };
int B[MAXN][MAXN];
int cnt = 0;
int d = 1;
void dfs(int a,int b) {
	if (cnt > N)return;
	if (a <= 0 || a > m || b <= 0 || b > n)return;
	if (v[a][b] == 1)return;
	v[a][b] = 1;
	B[a][b] = A[cnt++];
	if (d == 1) {
		if (b + 1 <= n && v[a][b + 1] == 0)dfs(a, b + 1);
		else d++;
	}
	if (d == 2) {
		if (a + 1 <= m && v[a + 1][b] == 0)dfs(a + 1, b);
		else d++;
	}

	if (d == 3) {
		if (b - 1 > 0 && v[a][b - 1] == 0)dfs(a, b - 1);
		else d++;
	}

	if (d == 4) {
		if (a - 1 > 0 && v[a - 1][b] == 0)dfs(a - 1, b);
		else  {
			d = 1;
			dfs(a, b + 1);
		}
	}
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(v[0], 0, MAXN * MAXN);
	memset(B[0], 0, MAXN * MAXN);
	scanf("%d", &N);
	m = (int)(ceil(sqrt(1.0*N)));
	while (N%m != 0)m++;
	n = N / m;
	for (int i = 0; i < N; i++) {
		scanf("%d",&A[i]);
	}
	sort(A, A + N,greater<int>());
	dfs(1,1);
	for (int i = 1; i <=m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", B[i][j]);
			if(j!=n)
				printf(" ");
		}
		printf("\n");
	}
	
	//printf();

	return 0;
}