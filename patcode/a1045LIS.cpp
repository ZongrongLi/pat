
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
int A[10200];
int Hash[10200] = { 0 };
int dp[10200] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	memset(Hash, -1, sizeof(Hash));
	scanf("%d", &n);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		Hash[t] = i;
	}
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (Hash[t] == -1)continue;
		A[cnt++] = Hash[t];
	}

	for (int i = 0; i < cnt; i++) {
		int Max = -1;
		for (int j = 0; j < i; j++) 
			if (Max < dp[j] && A[j] <= A[i])Max = dp[j];
		if (Max != -1)dp[i] = Max + 1;
		else dp[i] = 1;
	}
	printf("%d",dp[cnt-1]);
	return 0;
}

