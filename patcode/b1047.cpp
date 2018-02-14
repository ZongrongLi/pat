
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

int A[10010] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int maxd = -1;
	int maxg = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d-%d %d",&a,&b,&c);
		A[a] += c;
		if (maxg < A[a]) {
			maxg = A[a];
			maxd = a;
		}
	}

	printf("%d %d",maxd,maxg);

	return 0;
}