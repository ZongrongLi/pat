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
int n = 0,m;
int H[10000] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		H[t] = 1;
	}
	getchar();
	int ps = 0;
	int ic = 0;
	for (int i = 0; i < n; i++) {
		char s[8];
		int k;
		scanf("%s %d", s, &k);
		vector<int>tmp;
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d",&t);
			if (H[t] == 1) {
				tmp.push_back(t);
				ic++;
			}
		}
		if (tmp.size() > 0) {
			ps++;
			cout << s << ":";
			for (int i = 0; i < tmp.size(); i++)
				printf(" %04d", tmp[i]);
			cout << endl;
		}
	}
	//printf();
	cout << ps << " " << ic;
	return 0;
}