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
int A[10010][110];
bool c[10010][110];
int w[10200] = {0};
int flag[10010] = { 0 };
bool cmp(int a, int b) {
	return a > b;
}
int main() {    
	freopen("./test.txt", "r", stdin);
	memset(A[0], 0, 10010*110*4);
	memset(c[0], 0, 10010 * 110);
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = w[i]; v <= m; v++) {
			if (A[i - 1][v]<=A[i - 1][v - w[i]] + w[i]) {
				A[i][v] = A[i - 1][v - w[i]] + w[i];
				c[i][v] = 1;
			}
			else {
				A[i][v] = A[i - 1][v];
				c[i][v] = 0;
			}
		}
	}

	int v = m;
	int k = n;
	int num = 0;
	if (A[n][m] != m) {
		printf("No Solution");
		return 0;
	}
	else {
	
		while (k>=0)
		{
			if (c[k][v] == 1) {
				flag[k] = 1;
				v -= w[k];
				num++;
			}
			else flag[k] = 0;
			k--;
		}
	}
	for (int i = n; i >= 1; i--) {
		if (flag[i] == 1) {
			printf("%d", w[i]);
			num--;
			if (num != 0)printf(" ");
		
		}
	}
	//printf();

	return 0;
}

