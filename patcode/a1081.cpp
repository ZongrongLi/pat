
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
#define LL long long
LL gcd(LL a, LL b) {
	if (b == 0)return a;
	return gcd(b,a%b);
}

LL glc(LL a, LL b) {
	LL gcD = gcd(a, b);
	return gcD * (a / gcD)*(b / gcD);
}

class ration {
public:
	LL num;
	LL deno;
	LL intiger;
	ration() {
		num = 0;
		intiger = 0;
		deno = 1;
	}
	void yue() {
		LL gcD = gcd(abs(num), abs(deno));
		num /= gcD;
		deno /= gcD;
	}

	void jia() {
		LL t = intiger;
		intiger += num / deno;
		num -= deno * (intiger-t);
	}

	ration operator +(const ration &t) {
		LL glC = glc(abs(this->deno), abs(t.deno));
		
		ration tmp;
		tmp.num = this->num *(glC/this->deno) + t.num*(glC/t.deno);
		tmp.deno = glC;
		tmp.intiger = this->intiger + t.intiger;
		tmp.yue();
		tmp.jia();
		return tmp;
	}
};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	ration sum;
	for (int i = 0; i < n; i++) {
		ration tmp;
		scanf("%lld/%lld",&tmp.num,&tmp.deno);
		sum = sum + tmp;
	}
	if (sum.intiger > 0) {
		if (sum.num != 0)
			printf("%lld %lld/%lld", sum.intiger, sum.num, sum.deno);
		else
			cout << sum.intiger;
	}
	else {
		
		if (sum.num != 0)
			printf("%lld/%lld", sum.num, sum.deno);
		else
			printf("0", sum.num, sum.deno);

	}

	return 0;
}
