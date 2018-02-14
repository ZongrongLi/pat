
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
bool isp(string s) {
	int i = 0;
	int j = s.size() - 1;
	while (i<=j)
	{
		if (s[i] != s[j])return false;
		i++;
		j--;
	}
	return true;
}
string add(string s1, string s2) {

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string ans;
	int len = max(s1.size(), s2.size());
	int c = 0;
	for (int i = 0; i < len; i++) {
		int a =0;
		if(i<s1.size())
			a = s1[i] - '0';
		int b = 0;
		if(i<s2.size())
			b = s2[i] - '0';
		
		ans.push_back((a + b +c) % 10 + '0');
		c = (a + b + c) / 10;
	}
	if (c != 0)ans.push_back(c + '0');
	reverse(ans.begin(), ans.end());
	return ans;

}
int main() {
	freopen("./test.txt", "r", stdin);
	string str;
	cin >> str;
	string pre =str;
	string tmp;
	int cnt = 0;
	while (!isp(pre)){
		reverse(str.begin(), str.end());
		tmp = add(pre, str);
		printf("%s + %s = %s\n",pre.c_str(),str.c_str(),tmp.c_str());
		pre = tmp;
		str = pre;
		if (cnt++ >= 9)break;
	}
	if (cnt < 10)
		printf("%s is a palindromic number.", str.c_str());
	else
		printf("Not found in 10 iterations.");
	return 0;
}