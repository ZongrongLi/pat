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
#include<map>
using namespace std;
int n = 0,m,s;

map<string, int>mp;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d", &m,&n,&s);
	if (s > m) {
		cout << "Keep going..." << endl;
		return 0;
	}
	int cnt = 0;
	int t = s;
	string str;
	while (t--)cin >> str;
	cout << str << endl;
	mp[str] = 1;
	for (int i = s; i < m; i++) {
		
		cin >> str;
		cnt++;
		if (mp[str] != 1) {
			if (cnt >= n) {
				mp[str] = 1;
				cnt = 0;
				cout << str << endl;
			}
		}

	}
	//printf();

	return 0;
}