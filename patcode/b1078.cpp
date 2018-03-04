
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
char n;
vector<string>buff;
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%c", &n);
	getchar();
	string s;
	string t;
	getline(cin,s);
	t.push_back(s[0]);
	buff.push_back(t);
	if (n == 'C') {
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == buff.back()[0]) {
				buff.back().push_back(s[i]);
			}
			else {
				string tmp;
				tmp.push_back(s[i]);
				buff.push_back(tmp);
			}
		}
		for (int i = 0; i < buff.size(); i++) {
			if (buff[i].size() == 1)printf("%c",buff[i][0]);
			else printf("%d%c",buff[i].size(), buff[i][0]);
		}
	}
	if (n == 'D') {
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				int tmp = 0;
				string tmps;
				tmps.push_back(s[i]);
				i++;
				while (isdigit(s[i]))tmps.push_back(s[i++]);
				tmp = atoi(tmps.c_str());
				for (int j = 0; j < tmp; j++) {
					printf("%c", s[i]);
				}
				
			}
			else
				printf("%c", s[i]);
		}
	}
	//printf();

	return 0;
}
