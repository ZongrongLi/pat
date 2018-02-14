
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define LL long long

LL calcP(LL k,LL da) {
	LL ans = 0;
	while (k != 0) {
		if (k % 10 == da)ans = ans * 10 + k % 10;
		k = k / 10;
	}
	return ans;
}
int main() {
	freopen("./test.txt", "r", stdin);
	LL a, da, b, db;
	
	scanf("%lld %lld %lld %lld", &a, &da, &b, &db);
	LL c1 = calcP(a, da);
	LL c2 = calcP(b, db);
	printf("%d",c1+c2);

	return 0;
}

