
#include<cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;


int n, m,bn,ed;


int A[1010][1010];
int B[1010][1010];
vector<int>path[1010];

int lowcost[1010];
#define INF 0xfffffff
int v[1010] = { 0 };
vector<int> dfspath;
void distra(int k) {

	
	lowcost[k] = 0;
	for (int l = 0; l < n; l++) {
		int  u = -1;
		int min = INF;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0 && lowcost[i] < min) {
				min = lowcost[i];
				u = i;
			}
		}
		if (u == -1)return;
		v[u] = 1;

		for (int i = 0; i < n; i++) {
			if (v[i] == 1 || A[u][i] == 0)continue;
			if (lowcost[u] + A[u][i] < lowcost[i]) {
				lowcost[i] = lowcost[u] + A[u][i];
				path[i].clear();
				path[i].push_back(u);
			}
			else if(lowcost[u] + A[u][i] == lowcost[i]){
				path[i].push_back(u);
			}
		}
	}
	return;
}

int mincost = INF, mindis = 0;
vector<int> minpath;
void dfs(int k) {
	dfspath.push_back(k);
	if (k == bn) {
		int cost =0, dist=0;
		for (int i = 0; i < dfspath.size()-1; i++) {
			dist += A[dfspath[i]][dfspath[i + 1]];
			cost += B[dfspath[i]][dfspath[i + 1]];
		}
		if (mincost > cost) {
			mindis = dist;
			mincost = cost;
			minpath = dfspath;
		}
		dfspath.pop_back();
		return;
	}
	
	for (int i = 0; i < path[k].size(); i++)
		dfs(path[k][i]);
	dfspath.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &bn,  &ed);

	for (int i = 0; i < m; i++) {
		int a, b,c,d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A[a][b] = A[b][a] = c;
		B[a][b] = B[b][a] = d;
	}

	fill(lowcost, lowcost + 1010, INF);
	distra(bn);
	dfs(ed);
	for (int i = minpath.size()-1; i >=0; i--)
		printf("%d ",minpath[i]);
	printf("%d %d", mindis, mincost);
	return 0;
}