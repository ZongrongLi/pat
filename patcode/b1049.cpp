
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
double A[100200];
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf",&A[i]);
	}
	double sum = 0;
	double t = 0;
	for (int i = 1; i <= n; i++) {
		sum += t = t +  A[i] * i ;
	}
	printf("%.2lf",sum);
	
	//printf();

	return 0;
}


