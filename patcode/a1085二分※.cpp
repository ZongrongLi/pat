 
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
#define LL long long
LL A[100010];
int main() {
	freopen("./test.txt", "r", stdin);
	LL n = 0,p;
	LL tt = 1.6;
	scanf("%lld %lld", &n,&p);
	for (LL i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	//printf();
	sort(A, A + n);
	LL i = 0, j = n - 1;
	LL maxl = -1;
	for (LL j = n - 1; j >= 0; j--){	
		LL t = ceil(1.0*A[j] / p);
		i = lower_bound(A, A + j, t)-A;
		if (maxl < j - i + 1)maxl = j - i + 1;
	}
	printf("%lld",maxl);
	return 0;
}
