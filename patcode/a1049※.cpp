
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
	int sum = 0;
	int base = 1;
	int tt = n;
	while (tt>0)
	{
		int a, b, c;
		a = n / (base * 10);
		b = n /base % 10;
		c = n % base;
		if (b == 0)sum += a * base;
		else if (b == 1)sum += (a) *base+ c+1;
		else sum +=  (a + 1)*base;
		base *= 10;
		tt /= 10;
	}

	printf("%d",sum);
	//printf();

	return 0;
}
