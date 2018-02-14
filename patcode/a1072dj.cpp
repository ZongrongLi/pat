
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
int n = 0,m,k,ds,N;
#define INF 0x3fffffff
int A[1200][1200];
int d[1200];
int vis[1200] = {0};
void dijtstra(int k) {
	fill(d, d + 1200, INF);
	fill(vis, vis + 1200, 0);
	d[k] = 0;
	for (int i = 1; i <=N; i++) {
		int u = -1;
		int Min = INF;
		for (int j = 1; j <= N; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 1; v <= N; v++) {
			if (vis[v] == 1 || A[u][v] == INF)continue;
			if (d[v] > d[u] + A[u][v]) {
				d[v] = d[u] + A[u][v];
			}
		}

	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 1200 * 1200, INF);
	scanf("%d %d %d %d\n", &n,&m,&k,&ds);
	N = m + n;
	for (int i = 0; i < k; i++) {
		char s1[20], s2[20];
		int t;
		scanf("%s %s %d\n",s1,s2,&t);
		int a, b;
		if (s1[0] != 'G') 
			a = atoi(s1);
		
		else a = atoi(s1 + 1)+n;

		if (s2[0] != 'G')
			b = atoi(s2);

		else b = atoi(s2 + 1)+n;
		A[a][b] = A[b][a] = t;
	}
	int Mind = -1;
	double minPsum = 0;
	int minidx = -1;
	bool totflag = false;
	for (int i = n + 1; i <= N; i++) {
		int tMind = INF;
		double tsum = 0;
		dijtstra(i);
		bool flag = false;
		for (int j = 1; j <= n; j++) {
			if (tMind > d[j]) {
				tMind = d[j];
			}
			if (ds < d[j]) {
				flag = true;
				break;
			}
			tsum += d[j];
		}
		if (flag)continue;
		else totflag = true;
		if (Mind < tMind) {
			Mind = tMind;
			minPsum = tsum;
			minidx = i;
		}
		else if (Mind == tMind && tsum < minPsum) {
			minPsum = tsum;
			minidx = i;
		}
	}
	if (totflag)
		printf("G%d\n%.1f %.1f", minidx - n, 1.0*Mind, minPsum / n);
	else
		printf("No Solution");

	return 0;
}
