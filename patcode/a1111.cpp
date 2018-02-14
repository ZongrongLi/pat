
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
int n = 0,m;
#define INF 0x3fffffff
vector<int>pre[2000];
vector<int>pre1[2000];
int T[2000] = { 0 };
int d[2000] = { 0 };

int vis[2000] = { 0 };
int c1, c2;
class node {
public:
	int t;
	int d;
	node(){
		 d = INF;	
		 t = INF;
	}
};
node A[600][600];
void dijkstra1(int k) {
	fill(d, d + 2000, INF);
	//fill(T, T + 2000, INF);
	memset(T, 0, sizeof(T));
	memset(vis, 0, sizeof(vis));
	d[k] = 0;
	//T[k] = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		int Min = INF;
		int u = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (vis[v] == 1 || A[u][v].d == INF)continue;
			if (d[v] > d[u] + A[u][v].d) {
				d[v] = d[u] + A[u][v].d;
				T[v] = T[u] + A[u][v].t;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (d[v] == d[u] + A[u][v].d) {
				if (T[v] > T[u] + A[u][v].t) {
					T[v] = T[u] + A[u][v].t;
					pre[v].push_back(u);
				}
				
			}
		}
	}
}
//memst v
vector<int>tmp;
vector<int>ans1;
vector<int>ans2;
int MinT = -1;
void dfs1(int k) {
	tmp.push_back(k);
	
	if (k == c1) {
		/*int sum = 0;
		for (int i = 1; i < tmp.size(); i++) {
			sum += A[tmp[i]][tmp[i-1]].t;
		}
		if (sum == MinT)*/
		ans1 = tmp;
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < pre[k].size(); i++) {
		dfs1(pre[k][i]);
	}
	tmp.pop_back();
}


void dijkstra2(int k) {
	fill(T, T + 2000, INF);
	memset(vis, 0, sizeof(vis));
	T[k] = 0;


	for (int i = 0; i < n; i++) {
		int Min = INF;
		int u = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 1)continue;
			if (Min > T[j]) {
				Min = T[j];
				u = j;
			}
		}
		
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (vis[v] == 1||A[u][v].t==INF)continue;
			if (T[v] > T[u] + A[u][v].t) {
				T[v] = T[u] + A[u][v].t;
				pre1[v].clear();
				pre1[v].push_back(u);
			}
			else if (T[v] == T[u] + A[u][v].t) {
				pre1[v].push_back(u);
			}
		}
	}
}
int MinI = INF;
void dfs2(int k) {
	tmp.push_back(k);
	if (k == c1) {
		if (MinI > tmp.size()) {
			MinI = tmp.size();
			ans2 = tmp;
		}
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < pre1[k].size(); i++) {
		dfs2(pre1[k][i]);
	}
	tmp.pop_back();
}
bool equal(vector<int>&a,vector<int>&b) {
	if (a.size() != b.size())return false;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	//fill(A[0], A[0] + 1000 * 1000, INF);
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		
		int a, b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		A[a][b].d = d;
		A[a][b].t = e;
		if (c == 0) {
			A[b][a].d = d;
			A[b][a].t = e;
		}
	}
	scanf("%d %d",&c1,&c2);
	//printf();
	dijkstra1(c1);
	
	MinT = T[c2];
	dfs1(c2);
	


	dijkstra2(c1);
	tmp.clear();
	dfs2(c2);
	if (equal(ans1,ans2)) {
		printf("Distance = %d; Time = %d: ",d[c2],MinT);
		for (int i = ans1.size()-1; i >= 0; i--) {
			if(i!=0)
				printf("%d -> ",ans1[i]);
			else 
				printf("%d", ans1[i]);
		}
		return 0;
	}

	printf("Distance = %d: ",d[c2]);
	for (int i = ans1.size() - 1; i >= 0; i--){
		if (i != 0)
			printf("%d -> ", ans1[i]);
		else
			printf("%d", ans1[i]);
	}

	printf("\nTime = %d: ", T[c2]);
	for (int i = ans2.size() - 1; i >= 0; i--) {
		if (i != 0)
			printf("%d -> ", ans2[i]);
		else
			printf("%d", ans2[i]);
	}

	return 0;
}


