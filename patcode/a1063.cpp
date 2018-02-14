
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

set<int> S[55];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d",&t);
		for (int j = 0; j < t; j++)
		{
			int tmp;
			scanf("%d",&tmp);
			S[i].insert(tmp);
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		set<int>:: iterator it;
		int cnt = 0;
		for (it = S[a].begin(); it != S[a].end(); it++) {
			if (S[b].find(*it) != S[b].end())cnt++;
		}
		int c = S[a].size() + S[b].size()-cnt;
		printf("%.1f%%\n",1.0*cnt/c*100);
	}
	//printf();

	return 0;
}
