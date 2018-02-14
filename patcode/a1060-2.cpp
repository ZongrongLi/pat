
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;


int main() {
	freopen("./test.txt", "r", stdin);
	int  n = 0;
	double a, b;
	scanf("%d", &n);
	cin >> a >> b;
	int powa = 0, powb = 0;
	
	while (a>1)
	{
		a /= 10;
		powa++;
	}
	while (b > 1) {
		b /= 10;
		powb++;
	}
	
	while (((a - 0) > 10e-8)&&a < 0.1) {
		a *= 10;
		powa--;
	}
	while (((b - 0) > 10e-8)&&b < 0.1) {
		b *= 10;
		powb--;
	}
	int t = n;
	while (t--) {
		a *= 10;
		b *= 10;
	}
	int a1 = (int)a;
	int b1 = (int)b;
	if (a1 != 0 && b1 != 0) {
		if (a1 == b1 && powa == powb)
			printf("YES 0.%d*10^%d", a1, powa);
		else {
			printf("NO 0.%d*10^%d 0.%d*10^%d", a1, powa, b1, powb);
		}
	}
	else {//´¦Àí0
		if (a1 ==0 && b1 == 0) {
			printf("YES 0.");
			while (n--)cout << '0';
			printf("*10^0");
		}
		else if (a1 == 0) {
			printf("NO 0.");
			while (n--)cout << '0';
			printf("*10^0 ");
			printf("0.%d*10^%d", b1, powb);
		}
		else if (b1 == 0) {
			printf("NO 0.");
			printf("0.%d*10^%d", a1, powa);
			while (n--)cout << '0';
			printf("*10^0");
			
		}
			
}
	return 0;
}