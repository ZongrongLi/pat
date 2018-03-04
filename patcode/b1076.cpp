
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
	getchar();
	string ans;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin,s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') {
				ans.push_back( s[j - 2] - 'A' +'1');
			}
		}
	}
	cout << ans;
	return 0;
}
