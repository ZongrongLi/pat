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

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	double Max = -1;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int c = a * a + b * b;
		double d = sqrt(1.0*c);
		if (Max < d)Max = d;
	}
	printf("%.2f",Max);

	return 0;
}