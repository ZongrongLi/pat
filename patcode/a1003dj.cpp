
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
#define INF 0x3fffffff
int n = 0,m,c1,c2;
int w[1010] = {0};
int A[1010][1010];
int d[1010];
int vis[1010] = { 0 };
int weight[1010] = {0};
int num[1010] = { 0 };
void djktstra(int k) {
	fill(d, d + 1010, INF);
	fill(weight, weight + 1010, 0);
	d[k] = 0;
	weight[k] = w[k];
	num[k] = 1;
	for (int i = 0; i < n; i++) {
		int miN = INF;
		int v = -1;
		for (int u = 0; u < n; u++) {
			if (vis[u] == 1)continue;
			if (miN > d[u]) {
				miN = d[u];
				v = u;
			}
		 }
		if (v == -1)return;
		vis[v] = 1;
		for (int j = 0; j < n; j++) {
			if (A[v][j] == INF||vis[j]==1)continue;
			if (A[v][j] + d[v] < d[j]) {
				d[j] = A[v][j] + d[v];
				weight[j] = weight[v] + w[j];
				num[j] = num[v];
			}
			else if (A[v][j] + d[v] == d[j]) {
				if (weight[j] < weight[v] + w[j])
					weight[j] = weight[v] + w[j];
				num[j] += num[v];
			}
		}

	}

}



int main() {
	freopen("./test.txt", "r", stdin);
	//memset(A, 0, sizeof(A));
	fill(A[0], A[0] + 1010 * 1010, INF);
	scanf("%d %d %d %d", &n,&m,&c1,&c2);
	for (int i = 0; i < n; i++) {
		scanf("%d",&w[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		A[b][a] =A[a][b] = c;
	}
	djktstra(c1);
	printf("%d %d",num[c2],weight[c2]);

	return 0;
}
