
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
#define INF 0x3fffffff
int n, m, c1, c2;
int num[1200] = {0};
int vis[1200] = { 0 };
int A[1200][1200];
int w[1200] = { 0 };
int weight[1200] = {0};

int d[1200] = { 0 };
set<int>pre[1200];
queue<int> q;
int cnt[1200] = { 0 };
void spfa(int k) {
	fill(d, d + 1200, INF);
	d[k] = 0;
	num[k] = 1;
	w[k] = weight[k];
	q.push(k);
	vis[k] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int v = 0; v < n; v++) {
			if (A[u][v] == INF)continue;
			
			if (d[v] > d[u] + A[u][v]) {
				d[v] = d[u] + A[u][v];
				
				pre[v].clear();
				pre[v].insert(u);
				w[v] = w[u] + weight[v];
				num[v] =num[u];
				
				if (vis[v] == 0) {
					vis[v] = 1;
					q.push(v);
					//cnt[v]++;
					//if(cnt>=n)//判负环
				}
			}
			else if (d[v] == d[u] + A[u][v]) {
				pre[v].insert(u);
				if (w[v] < w[u] + weight[v]) {
					w[v] = w[u] + weight[v];
				}
				num[v] = 0;
				set<int>::iterator it = pre[v].begin();
				for (; it != pre[v].end(); it++) {
					num[v] += num[*it];
				}
				if (vis[v] == 0) {
					vis[v] = 1;
					q.push(v);
					//cnt[v]++;
					//if(cnt>=n)//判负环
				}
			}
			
		}
	}


}

int main() {
	fill(A[0], A[0] + 1200 * 1200, INF);
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d", &n,&m,&c1,&c2);

	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);
		A[a][b] = A[b][a] = c;
	}
	//printf();
	spfa(c1);
	printf("%d %d",num[c2],w[c2]);
	return 0;
}