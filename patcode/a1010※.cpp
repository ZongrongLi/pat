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

LL tradix(string k, LL r) {
	LL t = 0;
	for (int i = 0; i <k.size(); i++) {
		t *= r;
		
		if (isdigit(k[i])) {
			if ((k[i] - '0') >= r)return -2;
			t += k[i] - '0';
		}
		if (isalpha(k[i])) {
			if ((k[i] - 'a'+10) >= r)return -2;
			t += k[i] - 'a'+10;
		}
		if (t < 0)return -1;
	}
	return t;
}


int main() {

	freopen("./test.txt", "r", stdin);
	LL tag,radix;
	string n1, n2;
	cin >> n1 >> n2;
	scanf("%lld %lld",&tag,&radix);
	if (tag == 2) {
		string tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	LL dst = 0;
	dst = tradix(n1, radix);
	if (dst < 0) {
		cout << "Impossible";
		return 0;
	}
	LL mid;
	LL left =0;
	LL right =dst+100;
	bool flag = false;
	int minl = 0;
	while (left<=right)
	{
		mid = (right + left) / 2;
		
		LL t = tradix(n2, mid);
		if (t!=-1&&t < dst) {
			left = mid + 1;
		}
		else if (t > dst||t==-1)
			right = mid - 1;
		
		else if(t1==tmp{
			minl = mid;
			flag = true;
			right = mid - 1;
		}

	}
	if (!flag)cout << "Impossible";
	else cout << minl;
	return 0;
}