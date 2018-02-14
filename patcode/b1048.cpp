
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
int A[1010];
int B[1010];
vector<char> ve;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	string as, bs;
	cin >> as >> bs;
	reverse(as.begin(), as.end());
	reverse(bs.begin(), bs.end());
	int al = as.size();
	int bl = bs.size();
	if (al < bl) {
		for (int i = 0; i < bl-al; i++) {
			as.append("0");
		}
	}

	if (bs.size() < as.size()) {
		for (int i = 0; i <al-bl; i++) {
			bs.append("0");
		}
	}
	int len = as.size();
	

	for (int i = 1; i <= len; i++) {
		if ((i & 1) == 1) {
			int t= (bs[i - 1] + as[i - 1] -'0'-'0') % 13;
			if (t < 10)ve.push_back( (char)(t+'0'));
			else {
				if(t==10)
					ve.push_back((char)('J'));
				if(t==11)
					ve.push_back((char)('Q'));
				if(t==12)
					ve.push_back((char)('K'));
			}
		}
		else {
			int t = bs[i - 1] - as[i - 1];
			if (t < 0)t += 10;
			ve.push_back(t+'0');
		}
	}
	for (int i = ve.size() - 1; i >= 0; i--)
		cout << ve[i];
	//printf();

	return 0;
}