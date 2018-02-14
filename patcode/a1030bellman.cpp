
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;
int A[1010][1010] = {0};
int B[1010][1010] = { 0 };
int n = 0, m = 0,st,ed;
const int INF = 0x3fffffff;
int lowcost[1010];
int weight[1010] = { 0 };
set<int> pre[1010];
int num[1010];
void bellman(int k) {
	fill(lowcost, lowcost + 1010, INF);
	fill(num,num + 1010, 0);
	fill(weight, weight + 1010, 0); 
	num[k] = 1;
	lowcost[k] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (A[u][v] == 0)continue;
				if (lowcost[v] > lowcost[u] +A[u][v] ) {
					lowcost[v] = lowcost[u] + A[u][v];
					weight[v] = weight[u] + B[u][v];
					pre[v].clear();
					pre[v].insert(u);
					num[v] = num[u];

				}
				else if (lowcost[v] == lowcost[u] + A[u][v]) {
					//pre[v].clear();
					pre[v].insert(u);
					num[v] =0;
					if(weight[v] > weight[u] + B[u][v])
						weight[v] = weight[u] + B[u][v];
					for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++) {
						num[v] += num[*it];
					}
				}
			}
		}
	}
}

vector<int>tmppath;
vector<int>anspath;
int mincost = INF;
int mindist = INF;
void dfs(int k) {
	tmppath.push_back(k);
	int cost=0, dist= 0;
	if (k == st) {
		for (int i = 0; i < tmppath.size()-1; i++) {
			cost += B[tmppath[i]][tmppath[i + 1]];
			dist += A[tmppath[i]][tmppath[i + 1]];
		}
		if (mincost > cost) {
			mincost = cost;
			anspath = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	

	for (set<int>::iterator it = pre[k].begin(); it != pre[k].end(); it++) 
		{
			if (A[k][*it] != 0)
				dfs(*it);
		}
	tmppath.pop_back();
	
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d %d", &n, &m,&st,&ed);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		A[a][b] = A[b][a] = c;
		B[a][b] = B[b][a] = d;
	}
	bellman(st);
	dfs(ed);
	for (int i = anspath.size() - 1; i >= 0; i--)
		printf("%d ",anspath[i]);
	printf("%d %d",lowcost[ed],mincost);

	return 0;
}
