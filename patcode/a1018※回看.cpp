
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
#define  INF 0x3fffffff
int n = 0,cm,c1,m;
int weight[1010];
int w[1010] = { 0 };
int A[1010][1010];
int d[1010];
int vis[1010] = { 0 };
vector<int>pre[1010];
void dijtastra() {
	fill(d, d + 1010, INF);
	d[0] = 0;
	for (int i = 0; i <= n; i++) {
		int Min = INF;
		int u = -1;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v <= n; v++) {
			if (A[u][v] == INF || vis[v] == 1)continue;
			if (d[v] > A[u][v] + d[u]) {
				d[v] = A[u][v] + d[u];
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (d[v] == A[u][v] + d[u]) {
				pre[v].push_back(u);
			}
		}
	}
	
}


vector<int> anspath;
vector<int>tmp;
int minR = INF;
int minS = INF;
void dfs(int k) {
	tmp.push_back(k);
	if (k == 0) {
		int send = 0, recv = 0;
		for (int i = tmp.size()-1;i>=0 ; i--){
			if (tmp[i] == 0)continue;
			int t = weight[tmp[i]] - cm / 2;
			if (t > 0)recv += t;
			else {
				if (recv > -1 * t) {
					recv += t;
				}
				else {
					send += t + recv;
					recv = 0;
				}
			}
		}
		if (minS > send*-1) {
			anspath = tmp;
			minS = -1 * send;
			minR = recv;
		}
		else if (minS == send * -1) {
			if (minR > recv) {
				anspath = tmp;
				minR = recv;
			}
		}
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < pre[k].size(); i++) 
		dfs(pre[k][i]);
	
	tmp.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 1010 * 1010, INF);
	scanf("%d %d %d %d",&cm, &n,&c1,&m);
	for (int i = 1; i <= n; i++) 
		scanf("%d",&weight[i]);
	
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		A[a][b] = A[b][a] = c;
	}
	dijtastra();
	dfs(c1);
	
	
	printf("%d ",minS);
	for (int i = anspath.size()-1; i >= 0; i--) {
		if(i!=0)
			printf("%d->", anspath[i]);
		else 
			printf("%d ", anspath[i]);
	}
	printf("%d",minR);
	return 0;
}
