
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


vector<int>vt[10200];
int v[10200] = { 0 };

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(i);
		vt[b].push_back(i);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int c;
		scanf("%d",&c);
		memset(v, 0, sizeof(v));
		for (int i = 0; i < c; i++) {
			int t;
			scanf("%d", &t);
			for (int j = 0; j < vt[t].size(); j++)v[vt[t][j]] = 1;
		}
		bool flag = false;
		for (int i = 0; i < m; i++)if (v[i] == 0)flag = true;
		if(flag )
			printf("No\n");
		else 
			printf("Yes\n");
	}
	//printf();

	return 0;
}