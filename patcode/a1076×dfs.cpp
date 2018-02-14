
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int A[2018][2018] = { 0 };

int n = 0, L = 0;
int cnt = 0;
int v[2018] = { 0 };
void dfs(int k,int d) {
	if (v[k] == 1)return;
	if (d > L)return;
	v[k] = 1;
	cnt++;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1)continue;
		if (A[k][i] != 0)dfs(i, d + 1);
	}

}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d",&c);
		for (int j = 0; j < c; j++) {
			int t;
			scanf("%d", &t);
			A[t][i] = 1;
		}
	}

	
	int testcnt = 0;
	scanf("%d", &testcnt);
	for (int i = 0; i < testcnt; i++) {
		int temp;
		cnt = 0;
		memset(v, 0, sizeof(int) * 2018);
		scanf("%d",&temp);
		dfs(temp,0);
		cnt = cnt - 1 >= 0 ? cnt - 1 : 0;
		printf("%d\n",cnt);
	}
	

	//printf();

	return 0;
}
