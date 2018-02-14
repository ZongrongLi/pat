
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Date {
public:
	int day;
	int month;
	int year;
	Date(){
		day = month = year = 0;
	}
	bool operator <(const Date&T) {
		if (this->year != T.year)return this->year < T.year;
		if (this->month != T.month)return this->month < T.month;
		return this->day < T.day;
			
	}
};

string maxs, mins;
Date maxT, minT;

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	minT.year = 65535;
	for (int i = 0; i < n; i++) {
		Date d1, d2;;
		string s;
		cin >>s;
		
		scanf("%d:%d:%d %d:%d:%d", &d1.year ,&d1.month ,&d1.day ,&d2.year ,&d2.month ,&d2.day);
		if (d1 < minT) {
			minT = d1; mins = s;
		}
		if (maxT < d2) {
			maxT = d2;
			maxs = s;
		}


	}
	cout << mins << " " << maxs;

	return 0;
}