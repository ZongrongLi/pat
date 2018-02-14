
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
	   double sum = 0.0;
	   double t = 0.0;
	   double tmp =0.0;
	for (int i = 1; i <= n; i++) {
		scanf("%lf",&tmp);
		t = t + tmp * (double)i;
		sum += t;
	}
	printf("%.2f\n",sum);

	return 0;
}


//int main()
//{
//	freopen("./test.txt", "r", stdin);
//	int n;
//	scanf("%d", &n);
//	double ans = 0;
//	for (int i = 0; i<n; i++) {
//		double a;
//		scanf("%lf", &a);
//		ans += a * (i + 1)*(n - i);
//	}
//	printf("%.2f\n", ans);
//	return 0;
//}


