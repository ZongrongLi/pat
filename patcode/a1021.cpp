
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
using namespace std;
int n = 0;
vector<int>A[10200];
int v[10200] = { 0 };
bool ishui= false;
int maxd = -1;
vector<int>ans;
vector<int>tmp;
void dfs(int f,int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	tmp.push_back(k);
	if (maxd < (int)tmp.size()) {
		maxd = tmp.size();
		ans.clear();
		ans.push_back(tmp[0]);
	}
	else if (maxd == (int)tmp.size()) {
		if((!ans.empty())&&ans.back()!=tmp[0])
			ans.push_back(tmp[0]);
	}
	for (int i = 0; i <A[k].size(); i++) {
		if (A[k][i] == k)continue;
		if (A[k][i] == f)continue;
		if (v[A[k][i]] == 1) {
			ishui = true;
			continue;
		}
		dfs(k,A[k][i]);
	}
	tmp.pop_back();
}



bool isdone() {
	for (int i = 1; i <= n; i++) 
		if (v[i] == 0)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		A[a].push_back(b);
		A[b].push_back(a);
	}
	//printf();
	dfs(0,1);
	maxd= -1;
	ans.clear();
	if (isdone() ) {
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			dfs(0,i);
		}
		if (!ishui) {
			sort(ans.begin(), ans.end());
			for (int j = 0; j < ans.size(); j++) {
				printf("%d\n", ans[j]);
			}
			return 0;
		}
	}
	memset(v, 0, sizeof(v));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1)continue;
		cnt++;
		dfs(0,i);
	}
	printf("Error: %d components",cnt);
	return 0;
}
