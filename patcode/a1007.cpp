//4
//-3 3 5 6 这种情况 i要输出最小值
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
int A[10200] = {0};
int dp[10200] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	dp[0] = A[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + A[i],A[i]);
	}
	int  k = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > dp[k])k = i;
	}
	int c = k;
	int t = dp[k];
	int li = 0;
	while (c>=0)
	{
		t -= A[c--];
		if (t == 0)li = c;
	}
	if(dp[k]>=0)
		printf("%d %d %d",dp[k],A[li+1],A[k]);
	else
		printf("0 %d %d", A[0], A[n-1]);
	//printf();

	return 0;
}

