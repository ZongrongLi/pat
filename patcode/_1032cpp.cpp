#include "stdafx.h"
#include <stdio.h>
int A[100001] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	int n;
	scanf("%d\n",&n);
	int a, b;
	int max = -1;
	int maxI = -1;
	while (n--) {
		scanf("%d %d\n",&a,&b);
		A[a] += b;
		if (max < A[a]) {
			max = A[a];
			maxI = a;
		}
	}
	printf("%d %d",maxI, max);
	return 0;
}