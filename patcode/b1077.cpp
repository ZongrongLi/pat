
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
int n = 0,m;

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		int tea;
		int sum = 0;
		scanf("%d", &tea);
		int Max = -1;
		int Min = 65535;
		int cnt = 0;
		for (int j = 1; j < n; j++) {
			int t;
			scanf("%d", &t);
			if (t<0 || t>m)continue;
			cnt++;
			sum += t;
			Max = Max < t ? t : Max;
			Min = Min > t ? t : Min;
		}
		sum -= Max;
		sum -= Min;
		printf("%d\n",(int)((1.0*sum / (cnt-2) + 1.0*tea) / 2 + 0.5));
	}
	//printf();

	return 0;
}
