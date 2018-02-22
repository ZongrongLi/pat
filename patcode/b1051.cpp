
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
double r1, p1, r2, p2;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%lf %lf %lf %lf", &r1,&p1,&r2,&p2);
	double a = r1*r2*cos(p1+p2);
	double b = r1*r2*sin(p1+p2);
	if (a < 0&&a>-0.005) {
		a = 0;
	}
	if (b<0&&b > -0.005) {
		b = 0;
	}
	if (b >= 0) {
		printf("%.2lf+%.2lfi", a, b);
	}
	else 
		printf("%.2lf%.2lfi", a, b);
	//printf();

	return 0;
}