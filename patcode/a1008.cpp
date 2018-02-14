
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


int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int cur = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		int diff = t - cur;
		if (diff > 0)sum += diff * 6;
		else if (diff < 0)sum += -1 * diff * 4;
		cur = t;
	}
	sum += n * 5;
	cout << sum;


	//printf();

	return 0;
}
