
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

class Data {
public:
	int year;
	int month;
	int day;
	Data() {
		year = month = day = 0;
	}
	bool operator <(const Data&T) {
		if (this->year != T.year)return this->year <T.year;
		if (this->month != T.month)return this->month < T.month;
		return this->day < T.day;
	}
};
class node {
public:
	string name;
	Data d;
	bool operator <(const node &T) {
		return this->d < T.d;
	}
};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	Data cur,pre;
	cur.year = 2014;
	cur.month = 9;
	cur.day = 6;
	pre.year = 2014 - 200;
	pre.month = 9;
	pre.day = 6;
	node maxp, minp;
	minp.d.year = 65535;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		node t;
		cin >> t.name;
		scanf("%d/%d/%d", &t.d.year, &t.d.month, &t.d.day);
		if (cur < t.d)continue;
		if (t.d < pre)continue;
		if (t < minp)minp = t;
		if (maxp < t)maxp = t;
		cnt++;
	}
	if (cnt != 0)
		cout << cnt << " " << minp.name << " " << maxp.name;
	else
		cout << cnt;
	//printf();

	return 0;
}