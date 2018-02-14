
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

int n = 0, m = 0,s=0,d=0;
int A[1010][1010] = { 0 };
int B[1010][1010] = { 0 };

class path {
public:
	vector<int>p;
	int cost;
	int dis;
	path() {
		cost = 0;
		dis = 0;
	}

	bool operator <(const path &T) {
		if (this->dis != T.dis)return this->dis < T.dis;
		return this->cost < T.cost;
		
	}
};
int v[1010] = { 0 };
int st[1010] = { 0 };
int top = -1;
vector<path> paths;

pair<int, int> calcw(path p) {
	int tdis = 0;
	int tcost = 0;
	for (int i = 0; i < p.p.size()-1; i++) {
		tdis+= A[p.p[i]][p.p[i + 1]];
		tcost += B[p.p[i]][p.p[i + 1]];
	}
	return make_pair(tdis, tcost);
}
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	st[++top] = k;

	if (k == d) {
		path tp;
		//tp.p.resize(top + 1);
		for (int i = 0; i <= top; i++) {
			tp.p.push_back( st[i]);
		}
		pair<int,int> pp =  calcw(tp);
		tp.dis = pp.first;
		tp.cost = pp.second;
		paths.push_back(tp);
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 1)continue;
		if (A[k][i] == 0)continue;
		dfs(i);
	}

	top--;
	v[k] = 0;

}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d %d", &n, &m,&s,&d);
	for (int i = 0; i < m; i++) {
		int c1, c2, dis, cost;
		scanf("%d %d %d %d", &c1, &c2, &dis, &cost);
		A[c1][c2] = dis;
		A[c2][c1] = dis;
		B[c1][c2] = cost;
		B[c2][c1] = cost;
	}

	dfs(s);

	sort(paths.begin(), paths.end());

	for (int i = 0; i < paths[0].p.size(); i++) {
		printf("%d ", paths[0].p[i]);

	}
	printf("%d %d", paths[0].dis, paths[0].cost);
	//printf();

	return 0;
}
