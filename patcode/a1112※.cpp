
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
int H[800] = {0};
int V[800] = { 0 };
vector< vector<char> > vt;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	string s,ans;
	cin >> s;
	int len = s.size();
	int idx = 1;
	vector<char>tmp;
	tmp.push_back(s[0]);
	vt.push_back(tmp);
	for (int i = 1; i < len; i++) {
		if (s[i] != vt.back()[0]||vt.back().size()>=n) {
			vector<char>tmp;
			tmp.push_back(s[i]);
			vt.push_back(tmp);
		}
		else {
			vt.back().push_back(s[i]);
		}
	}
	
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].size() < n)H[vt[i][0]] = 1;
	}
	for (int i = 0; i < vt.size(); i++) {
		if (H[vt[i][0]] == 0 && V[vt[i][0]] ==0) {
			cout << vt[i][0];
			V[vt[i][0]] = 1;
		}
	}
	cout << endl;
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].size() >= n&&H[vt[i][0]] == 0)cout << vt[i][0];
		else {
			for (int j = 0; j < vt[i].size(); j++)cout << vt[i][0];
		}
	}
	return 0;
}
