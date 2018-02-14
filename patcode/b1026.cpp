
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


int main() {
	freopen("./test.txt", "r", stdin);
	int a, b;
	scanf("%d %d", &a, &b);
	int c = b - a;
	c = (int)((1.0*c)/100 +0.5);
	int h = c / 3600;
	int m = c / 60 % 60;
	int s = c % 60;

	printf("%02d:%02d:%02d",h,m,s);
	//printf();

	return 0;
}

