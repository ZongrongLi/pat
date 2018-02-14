
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
#include <map>
using namespace std;

vector<string>split(string s) {
	vector<string> ans;
	string word;
	for (int i = 0; i < s.size(); i++) {
		if (!(isalpha(s[i]) || isdigit(s[i]) )) {
			if(word!="")
				ans.push_back(word);
			word.clear();
			continue;
		}
		char c;
		if(isalpha(s[i]))
			c = tolower(s[i]);
		else c = s[i];
			word.push_back(c);
	}
	if (word != "")ans.push_back(word);
	return ans;
}
map<string, int> A;
char str[1068676];
int main() {
	freopen("./test.txt", "r", stdin);
	
	fgets(str, 1068676,stdin);
	str[strlen(str) - 1] = '\0';
	vector<string>vt = split(str);
	int maxcount = 1;
	string maxname = vt[0];
	A[vt[0]] = 1;
	for (int i = 1; i < vt.size(); i++)
	{
		if (A.find(vt[i]) != A.end()) {
			A[vt[i]]++;
		}
		else
			A[vt[i]] = 1;

		if (maxcount < A[vt[i]]) {
			maxcount = A[vt[i]];
			maxname = vt[i];
		}
	}
	printf("%s %d",maxname.c_str(),maxcount);

	return 0;
}