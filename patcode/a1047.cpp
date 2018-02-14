
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

vector<vector<string> > A;
int main() {
	A.resize(5000);
	freopen("./test.txt", "r", stdin);
	int n = 0,k;
	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		getchar();
		string tstr;
		int ni;
		cin >> tstr;
		scanf("%d",&ni);
		int t = 0;
		for (int j = 0; j < ni; j++) {
			scanf("%d", &t);
			A[t].push_back(tstr);
		}
	}
	//printf();
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n",i,A[i].size());
		sort(A[i].begin(), A[i].end());
		for (int j = 0; j < A[i].size(); j++) {
			printf("%s\n",A[i][j].c_str());
		}
	}
	return 0;
}
