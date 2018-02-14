
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
#define  LL long long

int main() {
	freopen("./test.txt", "r", stdin);
	LL a1, a2, a3;
	LL b1, b2, b3;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1,&a2,&a3,&b1,&b2,&b3);
	LL l1 = a1 * 17 * 29 + a2 * 29 + a3;
	LL l2 = b1 * 17 * 29 + b2 * 29 + b3;
	
	LL II = l1 + l2;
	LL G = II / 29 / 17;
	LL S = II / 29 % 17;
	LL K = II - (G * 29 * 17) - (S*29);
	cout << G << '.' << S << '.' << K;

	return 0;
}