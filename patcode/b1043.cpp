
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

int a[10010] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		a[s[i]]++;
	}

	while (true)
	{
		bool flag = false;
		if (a['P'] > 0) {
			printf("P");
			a['P']--;
			flag = true;
		}
		if (a['A']>0) {
			printf("A");
			a['A']--;
			flag = true;
		}
		if (a['T'] > 0) {
			printf("T");
			a['T']--;
			flag = true;
		}
		
		if (a['e']>0) {
			printf("e");
			a['e']--;
			flag = true;
		}
		if (a['s'] > 0) {
			a['s']--;
			printf("s");
			flag = true;
		}
		if (a['t'] > 0) {
			printf("t");
			a['t']--;
			flag = true;
		}
		if (!flag)break;

	}
	//printf();

	return 0;
}