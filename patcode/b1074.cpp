
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

int main() {
	freopen("./test.txt", "r", stdin);

	string s1, s2, s3;
	string ans;
	cin >> s1 >> s2 >> s3;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	while (s2.size() < s1.size())s2.push_back('0');
	while (s3.size() < s1.size())s3.push_back('0');
	
	int c = 0;
	for (int i = 0; i < s1.size(); i++) {
		int base;
		if(s1[i]!='0')
			base = s1[i] - '0';
		else base = 10;
		int t = s2[i] + s3[i] - '0'*2 +c;
		ans.push_back((char)(t%base+'0'));
		c = t / base;
	}
	if (c != 0)ans.push_back(c+'0');
	reverse(ans.begin(), ans.end());
	int idx = 0;
	while (ans[idx++] == '0'&&idx<ans.size());
	
	ans = ans.substr(idx-1, ans.size() - idx+1);
	cout << ans;
	//printf();

	return 0;
}
