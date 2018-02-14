//dfs 超时 5分没了
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
int A[10200] = { 0 };
int vis[10200] = { 0 };
vector<int>tmp;
vector<int>ansp;
bool cmp(vector<int>&a, vector<int>&b) {
	int len = min(a.size(), b.size());
	for (int i = 0; i < len; i++)
		if (a[i] != b[i])return a[i] < b[i];
	return a.size()<b.size();
}
void dfs(int k,int I) {
	if (k < 0)return;
	if (vis[I] == 1)return;
	if (I != -1) {
		tmp.push_back(A[I]);
		vis[I] = 1;
	}
	if (k == 0) {
		if (cmp(tmp,ansp)) 
			ansp = tmp;
		tmp.pop_back();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (k - A[i] < 0)break;
		dfs(k - A[i], i);
	}
	if (I != -1) {
		tmp.pop_back();
		vis[I] = 0;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	ansp.push_back( 0x3fffffff);
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&A[i]);
	}
	sort(A+1, A + n+1);
	//printf();
	dfs(m,-1);
	if (ansp[0] == 0x3fffffff) {
		printf("No Solution");
		return 0;
	}
	for (int i = 0; i < ansp.size(); i++) {
		if (i != ansp.size() - 1)printf("%d ",ansp[i]);
		else printf("%d", ansp[i]);
	}
	return 0;
}

