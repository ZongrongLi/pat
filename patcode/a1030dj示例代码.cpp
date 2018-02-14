
#include<cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 510;//最大顶点数

const int INF = 1000000000;//无穷大

//n为顶点数，田为边数，st和ed分别为起点和终点
//G为距离矩阵，cost为花费矩阵

//d[]记录最短距离，mincost记录最短路径上的最小花费
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = { false }; //vis [i] ==true 表示顶点 l
vector<int> pre[MAXV]; //前驱

vector<int>tempPath, path;//临时时路径、最优路径



void Dijkstra(int s){

	fill(d, d + MAXV, INF);//fill函数将整个d数组赋为iNF(慎用memset)
	d[s] = 0;//起点8到达自身的距离为o

	for (int i = 0; i < n; i++) { //循环n次
		int u = -1, MIN = INF; //u使d [u]最小，MIN存放该最小的d[u]
		for (int j = 0; j<n; j++) {//找到未访问的顶点中d[]最小的
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {

				if (d[u] + G[u][v]<d[v]) {//以u为中介点使d[v]更小
					d[v] =d[u] + G[u][v] ;
					pre[v].clear();//清空pre[v]
					pre[v].push_back(u);//u为v的前驱
				}
				else if (d[u] + G[u][v] == d[v])//找到相同长度的路径
					pre[v].push_back(u);//u为v的前驱之
			}
		}
	}
}



void dfs(int v) {
	if (v == st) {
		tempPath.push_back(v);
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {

			int id = tempPath[i], idNext = tempPath[i - 1];

			tempCost += cost[id][idNext]; //jlhna id->idNext fJ
		}
		if (tempCost < minCost) {
			minCost = tempCost; //更新mincost
			path = tempPath;//更新path
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();

}


int main(){
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF); //
	fill(cost[0], cost[0]+ MAXV * MAXV, INF);
	for (int i = 0; i < m; i++) {
		
		scanf("%d %d", &u, &v);
		scanf("%d %d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st); //Dijkstra &AD
	dfs(ed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d\n", d[ed], minCost);
	return 0;
}