
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;
int n = 0, m = 0,st,ed;
int A[1010][1010] = {0};
const int INF = 0x3fffffff;
int w[1010];
int lowcost[1010];
set<int>pre[1010];//----------------------------------------------必须是set 因为多次访问过滤掉重复的
int num[1010];
int mindist = INF;
//int maxhand =0;
int maxhand[1010];
bool bellman(int key) {
	fill(lowcost, lowcost + n + 1, INF);
	fill(num, num + 1010, 0);
	fill(maxhand, maxhand + 1010, 0);
	lowcost[key] = 0;
	num[key] = 1;
	maxhand[key] = w[key];//------------------------------------------------☆
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++) {
				if (A[j][k] == 0)continue;
				if (lowcost[k] > lowcost[j] + A[j][k]) {
					lowcost[k] = lowcost[j] + A[j][k];
					maxhand[k] = maxhand[j]+ w[k];
					pre[k].clear();
					pre[k].insert(j);
					num[k] = num[j];
				}
				else if(lowcost[k] == lowcost[j] + A[j][k]){
					if (maxhand[k] < maxhand[j] + w[k]) {
						maxhand[k] = maxhand[j] + w[k];
					}
					num[k] = 0;
					pre[k].insert(j);
					for (set<int>::iterator v = pre[k].begin(); v != pre[k].end(); v++) {
						num[k] += num[*v];
					}
					
				}
			}
	}


	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (A[j][k] == 0)continue;
			if (lowcost[j] > lowcost[j] + A[j][k]) {
				return false;
			}
			
		}
	}

	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d %d", &n, &m,&st,&ed);
	for (int i = 0; i < n; i++) {
		scanf("%d",&w[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A[a][b] = c;
		A[b][a] = c;
	}
	//printf();
	bellman(st);
	printf("%d %d",num[ed],maxhand[ed]);
	return 0;
}
