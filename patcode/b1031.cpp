
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

int w[17] ={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int mm[11] = { 1, 0, 100, 9, 8, 7, 6, 5, 4, 3, 2 };
int main() {
	freopen("./test.txt", "r", stdin);
	int  m, n;
	cin >> n;
	bool flag = false;
	for (int u = 0; u < n; u++) {
		string s;
		cin >> s;
		char c = s.at(s.size() - 1);
		if (c != 'X')
			m = c-'0';
		else
			m = 100;
		string ss = s.substr(0, 17);
		int weight = 0;
		for (int i = 0; i < 17; i++) {
			weight += w[i]*(ss[i]-'0');
		}
		weight %= 11;
		if (weight == 2) {
			if (m != 100) {
				cout << s << endl;
				flag = true;
			}
		}
		else {
			if (m != mm[weight]) {
				cout << s << endl;
				flag = true;
			}
		}
	}
	if (!flag) {
		cout << "All passed\n";
	}
	//printf();

	return 0;
}