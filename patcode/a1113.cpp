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
int A[100200];
int main() {
	freopen("./test.txt", "r", stdin);
	int sum1 = 0;
	int sum2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
		sum1 += A[i];
	}
	sort(A, A + n);
	for (int i = 0; i < n / 2; i++)sum2 += A[i];
	if (n % 2 == 0)printf("0 ");
	else printf("1 ");
	sum1 -= sum2;
	printf("%d",sum1-sum2);
	//printf();

	return 0;
}