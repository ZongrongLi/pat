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
int w[10010] = {0};
int choice[10010][110];
int flag[10010] = {0};

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A[0],0,10010*110*4);
	memset(choice[0], 0, 10010 * 110 * 4);
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&w[i]);
	}
	sort(w + 1, w + 1 + n,cmp);
	//printf();
	for (int i = 1; i <= n; i++)
		for (int v = w[i]; v <= m; v++) {
			if (A[i-1][v] <= A[i - 1][v - w[i]]+w[i]) {
				A[i][v] = A[i - 1][v - w[i]]+w[i];
				choice[i][v] = 1;
			}
			else {
				A[i][v] = A[i - 1][v];
			}
		}

	if (A[n][m] != m) {
		printf("No Solution");
		return 0;
	}
	int cnt = 0;
	int k = n;
	for(int i=n;i>=1;i--)
	{
		if (choice[i][m] == 1) {
			m -= w[i];
			flag[i] = 1;
			cnt++;
		}
	}

	for (int i = n; i >= 1; i--) {
		if (flag[i] == 0)continue;
		printf("%d",w[i]);
		if (--cnt != 0)printf(" ");
	}
	return 0;
}
