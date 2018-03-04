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
int S[200];
int ans[200];
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &S[i]);
	}
	for (int i = 0; i < m; i++) {	
		scanf("%d", &ans[i]);
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			int t;
			scanf("%d",&t);
			if (t == ans[j]) {
				sum += S[j];
			}
		}
		printf("%d\n",sum);
	}
	//printf();

	return 0;
}