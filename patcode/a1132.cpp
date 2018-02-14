
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

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string s1 = s.substr(0, s.size() / 2);
		string s2 = s.substr( s.size() / 2,s.size());
		int a = atoi(s1.c_str());
		int b = atoi(s2.c_str());
		if (a == 0 || b == 0) {
			printf("No\n");
			continue;
		}
		int c = atoi(s.c_str());
		if (c % (a*b) == 0)printf("Yes\n");
		else printf("No\n");
	}
	//printf();

	return 0;
}