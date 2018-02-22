
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
int n = 0,D;
double e;

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %lf %d", &n,&e,&D);
	int cntme = 0;
	int cnte = 0;
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d",&d);
		int cnt = 0;
		for (int j = 0; j < d; j++) {
			double t;
			scanf("%lf",&t);
			if (t < e)cnt++;
		}
		double dv = 1.0*d / 2;
		if (dv<1.0*cnt&&d>D)cnte++;
		if (dv < 1.0*cnt&&d <= D)cntme++;
	}
	printf("%.1f%% %.1f%%",1.0*cntme/n*100, 1.0*cnte / n * 100);

	return 0;
}