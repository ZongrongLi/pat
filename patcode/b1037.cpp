
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
LL a1, b1, c1;
LL a2, b2, c2;

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&a1,&b1,&c1,&a2,&b2,&c2);

	LL int1 = a1 * 29 * 17 + b1 * 29 + c1;
	LL int2 = a2 * 29 * 17 + b2 * 29 + c2;
	LL ansint = int2 - int1;
	if (ansint < 0) {
		cout << '-';
		ansint *= -1;
	}
	int A = ansint / 29 / 17;
	int B = (ansint / 29) % 17;
	int C = ansint - A * 29 * 17 - B * 29;
	cout <<A << '.' << B<<'.'<< C;
	//printf();

	return 0;
}