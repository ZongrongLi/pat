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
int A[1000][1000];
int main() {
	freopen("./test.txt", "r", stdin);
	int l , r,d;
	scanf("%d %d %d %d %d", &n,&m,&l,&r,&d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] >= l && A[i][j] <= r)A[i][j] = d;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j != m - 1)
				printf("%03d ", A[i][j]);
			else
				printf("%03d", A[i][j]);	
		}
		cout << endl;

	}
	//printf();

	return 0;
}