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
	string s;
	cin >> s;
	char sigh = s[0];
	s = s.substr(1,s.size()-1);
	int i = 0;
	for (; i < s.size(); i++) {
		if (s[i] == 'E') {
			break;
		}
	}
	string d = s.substr(0, i);
	string es = s.substr(i + 1, s.size() - i);
	int e = atoi(es.c_str());
	string buff;
	string::iterator it;
	for (int i = 0; i < 10000; i++)buff.push_back('0');
	for (char c : d) {
		buff.push_back(c);
	}
	
	buff.push_back('E');
	for (int i = 0; i < 10000; i++)buff.push_back('0');
	for (it = buff.begin(); it != buff.end(); it++) {
		if ((*it) == '.')break;
		if ((*it) == 'E')break;
	}
	if((*it) != 'E')
		buff.erase(it);
	buff.insert(it + e,'.');
	i = 0;
	for (; i < buff.size(); i++)
		if (buff[i] != '0')break;
	if(sigh=='-')printf("-");
	if (buff[i] == '.')printf("0");
	bool flag = false;
	for (; i < buff.size(); i++) {
		if (buff[i] == 'E') {
			if (flag)break;
			else buff[i] = '0';
			flag = true;
		}
		if (buff[i] == '.') {
			if (flag)break;
			flag = true;
			if (buff[i+1]=='E')break;
		}
		printf("%c",buff[i]);
	}
	return 0;
}

