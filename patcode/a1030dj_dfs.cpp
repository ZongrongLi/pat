
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
int m, n,st,ed;
int A[1010][1010];
int B[1010][1010];
int v[1010] = { 0 };
const int INF = 0x3fffffff;
int lowcost[1010] = { 0 };
vector<int>pre[1010];
void djkstra(int k) {
	fill(v,v+1010,0);
	fill(lowcost, lowcost + 1010, INF);
	
//	v[k] = 1;
	lowcost[k] = 0;
	for (int i = 0; i < n; i++) {
		int min = -1;
		int mincost = INF;
		for (int j = 0; j < n; j++) {
			if (v[j] == 1)continue;
			if (mincost > lowcost[j]) {
				min = j;
				mincost = lowcost[j];
			}
		}


		if (min == -1)return;
		v[min] = 1;
		for (int j = 0; j < n; j++) {
			if (A[min][j] == 0)continue;
			if (v[j] == 1)continue;
			if (lowcost[min] + A[min][j] < lowcost[j]) {
				lowcost[j] = lowcost[min] + A[min][j];
				pre[j].clear();
				pre[j].push_back(min);
			}
			else if (lowcost[min] + A[min][j] == lowcost[j]) {
				pre[j].push_back(min);
			}
			
		}
	}
	
}

vector<int>tmppath;
vector<int>minpath;
int mindis = INF;
int mincost= INF;

void dfs(int k) {
	tmppath.push_back(k);
	if (k == st) {
		int cost = 0, dis = 0;
		for (int i = 0; i < tmppath.size() - 1; i++)
		{
			dis+= A[tmppath[i]][tmppath[i + 1]];
			cost += B[tmppath[i]][tmppath[i + 1]];

		}
		if (mindis >= dis&&mincost>=cost) {//只算cost就行了 因为都是最短路
			minpath = tmppath;
			mindis = dis;
			mincost = cost;
		}
		tmppath.pop_back();
		return;
	}

	for (int i = 0; i < pre[k].size(); i++) {
		dfs(pre[k][i]);
	}
	tmppath.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d %d", &n, &m,&st,&ed);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A[a][b] = A[b][a] = c;
		B[a][b] = B[b][a] = d;
	}

	djkstra(st);
	
	dfs(ed);
	for (int i = minpath.size() - 1; i >= 0; i--) {
		printf("%d ", minpath[i]);
	}
	printf("%d %d",mindis,mincost);
	
	return 0;
}