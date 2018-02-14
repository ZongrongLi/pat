
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
#include<set>
using namespace std;

int n, m, c1, c2;
#define INF 0x3fffffff
int A[1200][1200];
int d[1200] = { 0 };
int num[1200] = { 0 };
int weight[1200] = {0};
int w[1200] = { 0 };
set<int>pre[1200];
void bellman(int k){
	fill(d, d + 1200, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[k] = 0;
	w[k] = weight[k];
	num[k] = 1;
	for(int i=0;i<n-1;i++)
		for(int u=0;u<n;u++)
			for (int v = 0; v < n; v++) {
				if (A[u][v] == INF)continue;
			
				if (d[u] + A[u][v] < d[v]) {
					w[v] = w[u] + weight[v];
					d[v] = d[u] + A[u][v];
					pre[v].clear();
					pre[v].insert(u);
					num[v] = num[u];
				}
				else if (d[u] + A[u][v] == d[v]) {
					pre[v].insert(u);
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					num[v] = 0;
					set<int>::iterator it =pre[v].begin();
					for (; it != pre[v].end(); it++)
						num[v] += num[(*it)];
				}
			}

}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d", &n,&m,&c1,&c2);
	fill(A[0], A[0] + 1200 * 1200, INF);
	for (int i = 0; i < n; i++) 
		scanf("%d",&weight[i]);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		A[a][b] = A[b][a] = c;
	}
	bellman(c1);
	printf("%d %d",num[c2],w[c2]);
	//printf();

	return 0;
}