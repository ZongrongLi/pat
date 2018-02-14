
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
#include <sstream>

using namespace std;

string numa[13] = {
"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
string numA[13] = {
	"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

int getindexa(string s) {
	//if (s == "")return 0;
	if (s.size()==4)return 0;
	if (s[2] == 'n'&&s[1]=='a')return 1;
	if (s[2] == 'b')return 2;
	if (s[2] == 'r'&&s[0]=='m')return 3;
	if (s[2] == 'r'&&s[0]=='a')return 4;
	if (s[2] == 'y' &&s[0]=='m')return 5;
	if (s[2] == 'n'&&s[1]=='u')return 6;
	if (s[2] == 'y'&&s[0]=='j')return 7;
	if (s[2] == 'g')return 8;
	if (s[2] == 'p')return 9;
	if (s[2] == 't')return 10;
	if (s[2] == 'v')return 11;
	if (s[2] == 'c' )return 12;
}
int getindexA(string s) {
	if (s[2] == 'm')return 1;
	if (s[2] == 'l')return 2;
	if (s[2] == 'a')return 3;
	if (s[2] == 'h')return 4;
	if (s[2] == 'u' &&s[0]=='t')return 5;
	if (s[2] == 's')return 6;
	if (s[2] == 'i')return 7;
	if (s[2] == 'o')return 8;
	if (s[2] == 'y')return 9;
	if (s[2] == 'k')return 10;
	if (s[2] == 'r')return 11;
	if (s[2] == 'u' &&s[0]=='j')return 12;
}
int martoearth(string s) {
	string a, b;
	istringstream  f(s);
	f.clear();
	getline(f, a, ' ');
	getline(f, b, ' ');
	if (a==""||b=="") {
		string t;
		if (a == "")t = b;
		else t = a;
		for (int i = 0; i < 13; i++)
			if (t == numa[i])return getindexa(t);
		return getindexA(t)*13;
	}
	return getindexA(a) * 13 + getindexa(b);
	
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	//freopen("./out.txt", "w", stdout);

	
	int n = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		string t;
		//cin >> t;
		char tstr[200];
		fgets(tstr, 200, stdin);
		if (tstr[strlen(tstr) - 1] == '\n')tstr[strlen(tstr) - 1] = '\0';
		t = tstr;
		if (isalpha(t[0])) {
			int tmp = martoearth(t);
			printf("%d\n",tmp);
		}
		else {
			int tmp = atoi(t.c_str());
			int a = tmp / 13;
			int b = tmp % 13;
			if (a != 0) {
				if(b!=0)
					printf("%s %s\n", numA[a].c_str(), numa[b].c_str());
				else
					printf("%s\n", numA[a].c_str());
				
			}
			else 
				printf("%s\n", numa[b].c_str());
		}

	}
	//printf();

	return 0;
}
