//刚好有e天超过e公里 这个e不一定是曾经出现过的公里数，
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
#include <functional>
#include <string>
#include <set>
using namespace std;
int n = 0;
int A[100200] = {0};
int B[100200] = { 0 };

int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d", &n);
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	sort(A+1, A + n+1,greater<int>());
	int i = 1;
	for (; i <= n; i++)
		if (i >= A[i])break;
	printf("%d", i - 1);
	return 0;
}


