//读题意 and the number and its exponent's signs are always provided even when they are positive.
//是给出正号 而不是 让你打印出正号  
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

string s;
char *str = new char[100010];
int main() {
	freopen("./test.txt", "r", stdin);
	cin >> s;
	int i = 0;
	int dotI = 0;
	int cnt = 0;
	memset(str, 0, 100010);
	bool flag = false;
	while (s[i]!='E')
	{
		if (s[i] != '.')str[cnt++] = s[i];
		else {
			dotI = cnt - 1;
			flag = true;
		}
		i++;
		
	}
	str[i] = '\0';
	
	if (str[0] == '-')cout << "-";
	//else cout << "-";
	str += 1;
	if (!flag)dotI = strlen(str);
	cnt--;
	char *ts = new char[100050];
	memcpy(ts, s.c_str() + i + 1, s.size()-i);
	int eponent = atoi(ts);
	dotI += eponent;
	if (eponent < 0) {
		if (dotI <= 0) {
			cout << "0.";
			while (dotI < 0)
			{
				cout << '0';
				dotI++;
			}
			cout << str;
		}
		if (dotI > 0) {
			for (int i = 0; i < cnt; i++) {
				cout << str[i];
				if (i == dotI-1)
					cout << ".";
			}
		}
		
	}

	else {
		if (dotI < strlen(str)) {
			for (int i = 0; i < cnt; i++) {
				cout << str[i];
				if (i == dotI-1)
					cout << ".";
			}
		}
		else
		{
			cout << str;
			for (int i = 0; i < dotI - strlen(str); i++) {
				cout << "0";
			}
		}
	}
	//printf();

	return 0;
}