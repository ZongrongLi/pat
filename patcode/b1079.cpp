
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
bool ispalin(const string &s) {
	int i = 0,j = s.size() - 1;
	while (i <= j) {
		if (s[i] != s[j])return false;
		i++;
		j--;
	}
	return true;
}
string revadd(const string &s,const string &s1) {
	string ans;
	int  c = 0;
	for (int i = 0; i < s.size(); i++) {
		int t = s[i] - '0' + s1[i] - '0';
		ans.push_back((t+c) % 10+'0');
		c = (t + c) / 10;
	}
	if (c != 0)ans.push_back(c + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	freopen("./test.txt", "r", stdin);

	string s1,s2;
	cin >> s1;
	if (ispalin(s1)) {
		cout << s1 << " is a palindromic number." << endl;
		return 0;
	}
	int c = 10;
	while (1) {
		s2 = s1;
		reverse(s1.begin(), s1.end());
		string cs = revadd(s1, s2);
		cout<<s2<<" + "<<s1<<" = "<<cs<<endl;
		if (ispalin(cs)) {
			cout << cs << " is a palindromic number." << endl;
			break;
		}
		s1 = cs;
		c--;
		if (c == 0) {
			cout << "Not found in 10 iterations." << endl;
			break;
		}
	}
	//printf();

	return 0;
}
