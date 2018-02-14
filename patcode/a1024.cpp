
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

string add(string a, string b) {
	char s1[5000];
	char s2[5000];
	string ans;
	memset(s1,'0',sizeof(s1));
	memset(s2, '0', sizeof(s2));
	memcpy(s1, a.c_str(), a.size());
	memcpy(s2, b.c_str(), b.size());
	
	reverse(s1, s1 + a.size());
	reverse(s2, s2 + a.size());
	int len = max(a.size(), b.size());
	int c = 0;
	for (int i = 0; i < len; i++) {
		int t = s1[i] - '0' + s2[i] - '0' + c;
		ans.push_back(t%10+'0');
		c = t / 10;
	}
	if (c != 0)ans.push_back(c + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}

bool ispanlin(string s) {
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j])return false;
		i++; j--;
	}
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	string num;
	
	cin >> num;
	string tmp1 = num;
	string tmp2;
	int n = 0;
	scanf("%d", &n);
	
	int i = 0;
	for (i = 0; i < n; i++) {
		if (ispanlin(tmp1))break;
		tmp2 = tmp1;
		reverse(tmp1.begin(),tmp1.end());
		tmp1 = add(tmp1, tmp2);
	}
	cout << tmp1 << endl << i;
	//printf();

	return 0;
}
