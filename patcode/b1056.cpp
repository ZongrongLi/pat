
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
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		sum += (t * 10 + t)*(n - 1);
	}

	printf("%d",sum);

	return 0;
}