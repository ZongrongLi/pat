
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
#define  LL long long


LL gcd(LL a, LL b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

LL glc(LL a, LL b) {
	LL t = gcd(a,b);
	return t * (a / t)*(b / t);
}
class ratinal {
public:
	LL num;
	LL deno;
	LL Intig;
	void yue() {
		LL t = gcd(abs(this->num)  ,abs(this->deno));
		num /= t;
		deno /= t;
	}

	void hua() {
		
		Intig += num / deno;
		num = num % deno;
		if (Intig < 0)num =abs(num);
	}
	ratinal() {
		num = 0;
		deno = 1;
		Intig = 0;
	}

	ratinal operator +(const ratinal &t) {
		ratinal tmp;
		tmp.Intig = this->Intig + t.Intig;
		LL glC = glc(abs(this->deno), abs(t.deno));
		tmp.deno = glC;
		tmp.num = this->num *(glC / this->deno) + t.num*(glC / t.deno);
		tmp.yue();
		tmp.hua();
		return tmp;
	}

	ratinal operator -(const ratinal &tt) {
		ratinal t = tt;
		t.num *= -1;
		ratinal tmp;
		tmp.Intig = this->Intig + t.Intig;
		LL glC = glc(abs(this->deno), abs(t.deno));
		tmp.deno = glC;
		tmp.num = this->num *(glC / this->deno) + t.num*(glC / t.deno);
		tmp.yue();
		tmp.hua();
		return tmp;
	}

	ratinal operator *(const ratinal &t) {
		ratinal tmp;
		tmp.Intig = this->Intig *t.Intig;
		ratinal r1;
		r1.num = this->num *t.Intig;
		r1.deno = this->deno;
		ratinal r2;
		r2.num = t.num *this->Intig;
		r2.deno = t.deno;

		
		ratinal r3;
		r3.num = this->num * t.num;
		r3.deno = this->deno*t.deno;
		tmp = tmp + r1 + r2 +r3;
		tmp.yue();
		tmp.hua();
		return tmp;
	}

	ratinal operator /(const ratinal &t) {
		ratinal tmp;
		tmp.deno = this->deno *t.num;
		tmp.num = this->num *t.deno;
		if (tmp.deno < 0) {
			tmp.deno *= -1;
			tmp.num *= -1;
		}
		tmp.yue();
		tmp.hua();
		return tmp;
	}

	void output() {
		if (Intig == 0 && num == 0) {
			printf("0");
			return;
		}
		if (num < 0 || Intig < 0)cout << "(";
		if (Intig != 0) {
			if(num !=0)
				printf("%lld ", Intig);
			else 
				printf("%lld", Intig);
		}
		if (num != 0) {
			printf("%lld/%lld", num,deno);
		}
		if (num < 0|| Intig < 0)cout << ")";

	}
};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	
	
		ratinal r1, r2,d1,d2;
		scanf("%lld/%lld %lld/%lld",&r1.num,&r1.deno,&r2.num,&r2.deno);
		d1 = r1;
		d2 = r2;
		d1.yue();
		d1.hua();
		d2.yue();
		d2.hua();

		ratinal tmp;
		d1.output();
		cout << " + ";
		d2.output();
		tmp = r1 + r2;
		cout << " = ";
		tmp.output();

		cout << endl;

		ratinal tmp1;
		d1.output();
		cout << " - ";
		d2.output();
		tmp1 = r1 - r2;
		cout << " = ";
		tmp1.output();

		cout << endl;


		ratinal tmp2;
		d1.output();
		cout << " * ";
		d2.output();
		tmp2 = r1 * r2;
		cout << " = ";
		tmp2.output();

		cout << endl;


		ratinal tmp3;
		d1.output();
		cout << " / ";
		d2.output();
		cout << " = ";
		if (r2.num == 0) {
			cout << "Inf";
				return 0;
		}
		tmp3 = r1 / r2;
		tmp3.output();
		cout << endl;

	//printf();

	return 0;
}
