
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
int N = 0,m,n;
int A[10200];
int **v;
int **D;
bool test(int a, int b) {
	if (a <= 0 || a > m || b <= 0 || b > n)return false;
	if (v[a][b] == 1)return false;
	return true;
}
int d = 1;
int idx = 0;
void dfs(int a, int b) {
	if (v[a][b] == 1)return;
	v[a][b] = 1;
	D[a][b] = A[idx++];
	switch (d)
	{
	case 1:
		if (test(a, b + 1)) 
			dfs(a, b + 1);
		else d++;
	case 2:
		if (test(a+1, b))
			dfs(a+1, b);
		else d++;
	case 3:
		if (test(a, b - 1))
			dfs(a, b - 1);
		else d++;
	case 4:
		if (test(a-1, b))
			dfs(a-1, b);
		else {
			if (test(a, b + 1)) {
				d = 1;
				dfs(a, b + 1);
			}
		}
	default:
		break;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N, greater<int>());
	int c = (int)sqrt(1.0*N);
	for (int i = c; i >= 1; i--) {
		if (N%i == 0) {
			m = i;
			n = N / i;
			break;
		}
	}
	if (m < n)swap(m, n);
	v = new int*[m+1];
	D = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		v[i] = new int[n+1];
		D[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)v[i][j] = 0;
	}
	//printf();
	dfs(1, 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(j!=n)
			printf("%d ",D[i][j]);
			else 
				printf("%d\n", D[i][j]);
		}
	}
	return 0;
}