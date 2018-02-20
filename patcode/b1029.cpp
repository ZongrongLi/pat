
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
bool H[100200];
bool v[100200];
int main() {
	freopen("./test.txt", "r", stdin);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s2.size(); i++) {
		H[toupper( s2[i])] = 1;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (H[toupper(s1[i])] == 0 && v[toupper(s1[i])] == 0)
		{
			v[toupper(s1[i])] = 1;
			if (isalpha(s1[i]))
				printf("%c",toupper(s1[i]));
			else 
				printf("%c", s1[i]);
		}
	}
	//printf();

	return 0;
}
