
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
bool islegal(string s) {
	int dotc = 0;
	double tmp = atof(s.c_str());
	if (tmp < -1000.0 || tmp>1000.0)return false;
	if (s[0] == '-')s = s.c_str() + 1;
	for (int i = 0; i < s.size(); i++) {
		if ((!isdigit(s[i]))&&s[i]!='.')return false;
		if (s[i] == '.')dotc++;
		if (dotc >= 2)return false;
		if (dotc >= 1 && s.size() - i -1> 2)return false;
	}
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	double sum = 0.0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!islegal(s))
			printf("ERROR: %s is not a legal number\n", s.c_str());
		else {
			sum += atof(s.c_str());
			cnt++;
		}
	}
	if (cnt == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else {
		if(cnt!=1)
			printf("The average of %d numbers is %.2f",cnt,sum/cnt);
		else
			printf("The average of %d number is %.2f", cnt, sum / cnt);
	}
	//printf();

	return 0;
}
