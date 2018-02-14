
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
int H[2000] = { 0 };
int A[2000] = { 0 };
bool isfalse(int a,int b) {
	int t1 = abs(a - b);
	int t2 = abs(A[a] - A[b]);
	if (t1 == t2)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(H, 0, sizeof(H));
		memset(A, 0, sizeof(A));
		int m;
		bool flag = false;
		scanf("%d",&m);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &A[j]); 
		}
		for (int u = 1; u < m; u++) {
			for (int v = u + 1; v <= m; v++) {
				if (!isfalse(u, v)||A[u]==A[v]) {
					flag = true;
					printf("NO\n");
					break;
				}
			}
			if (flag)break;
		}
		if (!flag) {
			printf("YES\n");
		}
		
	}
	//printf();

	return 0;
}
