
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

string add(string a,string b) {
	char s1[30];
	char s2[30];
	string ans;
	memset(s1, '0', 30);
	memset(s2, '0', 30);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	memcpy(s1, a.c_str(),a.size());
	memcpy(s2, b.c_str(),b.size());
	int len = max(a.size(), b.size());
	int c = 0;
	for (int i = 0; i < len; i++) {
		int t = (s1[i]-'0' + s2[i]-'0' +c) % 10;
		c =  (s1[i] - '0' + s2[i] - '0') / 10;

		ans.push_back( t +'0');
	}
	if (c != 0)ans.push_back(c + '0');
	reverse(ans.begin(),ans.end());
	return ans;
}

int v[30] = {0};
int main() {
	freopen("./test.txt", "r", stdin);

	string n;
	cin >> n;
	string db =add(n, n);
	if (n.size() != db.size()) {
		cout << "No" << endl << db;
		return 0;
	}

	for (int i = 0; i < n.size(); i++)
		v[n[i] - '0']++;
	for (int i = 0; i < n.size(); i++) {
		v[db[i] - '0']--;
		if (v[db[i] - '0'] < 0) {
			cout << "No" << endl << db;
			return 0;
		}
	}
	for (int i = 0; i < n.size(); i++)
		if (v[n[i] - '0'] > 0) {
			cout << "No" << endl << db;
			return 0;
		}

	//printf();
	cout << "Yes" << endl << db;
	return 0;
}
