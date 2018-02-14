
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
#define INF 0x3fffffff
using namespace std;
int n = 0;
vector<vector<int> >vt;

int A[10000][10000];
int v[10000] = {0};
int st, ed;
vector<int> tmppath;
vector<int> ans;
int Min = 65535;
int Mincnt = 65535;
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	tmppath.push_back(k);
	if (k == ed) {
		int cnt = 0;
		for (int i = 1; i<tmppath.size() - 1; i++)
			if (A[tmppath[i]][tmppath[i - 1]] != A[tmppath[i]][tmppath[i + 1]]) {
				cnt++;
			}
		if (Min > tmppath.size()) {
				ans = tmppath;
				Min = ans.size();
				Mincnt = cnt;
			
		}
		else if (Min == tmppath.size()) {
			if (Mincnt > cnt) {
				ans = tmppath;
				Min = ans.size();
				Mincnt = cnt;
			}
		}
		v[k] = 0;
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < vt[k].size(); i++)
		dfs(vt[k][i]);
	v[k] = 0;
	tmppath.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d", &n);
	vt.resize(10000);
	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d",&m);

		int t;
		scanf("%d", &t);
		for (int j = 1; j < m; j++) {
			int c;
			scanf("%d", &c);
			vt[t].push_back(c);
			vt[c].push_back(t);
			A[t][c] = i;
			A[c][t] = i;
			t = c;
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d",&st,&ed);
		Min = 99999;
		Mincnt = 99999;
		ans.clear();
		tmppath.clear();
		memset(v, 0, sizeof(v));
		dfs(st);
		printf("%d\n",ans.size()-1);
		int pre = A[ans[0]][ans[1]];
		int bg = ans[0];
		for (int j = 1; j < ans.size()-1; j++) {
			if (A[ans[j-1]][ans[j]] != A[ans[j]][ans[j + 1]]) {
				printf("Take Line#%d from %04d to %04d.\n",pre,bg,ans[j]);
				bg = ans[j];
				pre = A[ans[j]][ans[j + 1]];
			}
			
		}
		
		printf("Take Line#%d from %04d to %04d.\n", pre, bg, ans[ans.size()-1]);
		
	}
	//printf();

	return 0;
}
