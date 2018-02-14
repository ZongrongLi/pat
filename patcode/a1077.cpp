
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

vector<string> v;

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d\n", &n);
	int  minl = 65535;
	for (int i = 0; i < n; i++) {
		char s[285];
		fgets(s, 285, stdin);
		if (s[strlen(s) - 1] == '\n')s[strlen(s) - 1] = '\0';
		reverse(s,  s +strlen(s));
		minl = minl > strlen(s) ? strlen(s) : minl;
		v.push_back(s);
	}
	int cnt = 0;
	int i;
	char t;
	while ((cnt++)<minl) {
		t = v[0][cnt];
		i = 1;
		for (; i < v.size(); i++) {
			if (v[i][cnt] != t)break;
			
		}
		if(i<v.size())
			if (v[i][cnt] != t)break;
	}
	if ((cnt==1) && (v[i][cnt] != t)) {
		
		cout << "nai";
	}
	else {
		string ans = v[0].substr(0, cnt);
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
		
	//printf();

	return 0;
}
