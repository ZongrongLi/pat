
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int INF = 0x3fffffff;

int m, n, st, ed;
int A[1010][1010] = {0};
int B[1010][1010] = {0};
int lowcost[1010] = { 0 };
queue<int>q;
int inq[1010] = {0};
int num[1010] = { 0 };
int weight[1010] = { 0 };
set<int>pre[1010];
void spfa(int  k) {
	q.push(k);
	inq[k] = 1;
	fill(lowcost, lowcost + 1010, INF);
	fill(num, num+ 1010, 0);
	fill(weight, weight+ 1010, 0);
	lowcost[k] = 0;
	num[k] = 1;

	while(!q.empty()){
		int  u = q.front();
		q.pop();
		inq[u] = 0;
		
			for (int v = 0; v < n; v++) {
				if (A[u][v] == 0)continue;
				if (lowcost[v] > lowcost[u] + A[u][v]) {
					lowcost[v] = lowcost[u] + A[u][v];
					pre[v].clear();
					pre[v].insert(u);
					weight[v] = weight[u] + B[u][v];
					if (inq[v] != 1) {
						q.push(v);
						inq[v] = 1;
						num[v]++;
					
					}
				}
				else if (lowcost[v] == lowcost[u] + A[u][v]) {
					if (weight[v] > weight[u] + B[u][v]) {
						weight[v] = weight[u] + B[u][v];
					}

					pre[v].insert(u);
				}
			}
		
	}
}
vector<int>tmppath;
vector<int>anspath;
int mincost = INF;
void dfs(int k) {
	tmppath.push_back(k);
	if (k == st) {
		
		int cost = 0;
		for (int i = 0; i <tmppath.size()-1; i++) {
			cost += B[tmppath[i]][tmppath[i+1]];
		}
		if (mincost > cost) {
			mincost = cost;
			anspath = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (set<int>::iterator it = pre[k].begin(); it!=pre[k].end(); it++) {
		dfs(*it);
	}
	tmppath.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m,&st,&ed);

	for (int i = 0; i < m; i++) {
		int a,b, c, d;
		scanf("%d %d %d %d" ,&a,&b,&c,&d);
		A[a][b] = A[b][a] = c;
		B[a][b] = B[b][a] = d;
	}
	spfa(st);
	dfs(ed);
	for (int i = anspath.size() - 1; i >= 0; i--) {
		printf("%d ",anspath[i]);
	}
	printf("%d %d", lowcost[ed], weight[ed]);
	//printf();

	return 0;
}

