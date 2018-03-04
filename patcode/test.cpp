#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include<iostream>
using namespace std;
#define lowbit(x) x&(-x)
int getsum(int x) {
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		sum += i;
	}
	return sum;
}
class Solution {
public:
	void replaceSpace(char *str, int length) {
		//getchar();
		string s;
		for (int i = 0; i<length; i++) {
			if (str[i] == ' ')s.append("%%20");
			else s.push_back(str[i]);
		}
		memset(str, 0, length + 1);
		memcpy(str, s.c_str(), s.size() + 1);
	}
};

void fun(const string &st) {
	cout << st[0];
	

}
int main() {
	freopen("./test.txt", "r", stdin);
	fun("heheheh");
	Solution s;
	char c[30] = { "We Are Happy" };
	s.replaceSpace(c,12);
	return 0;
}