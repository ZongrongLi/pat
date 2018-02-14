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

vector<int>A[100210];
int w[100200] = {0};
int v[100200] = { 0 };
double totsum = 0;
double p, r;
void dfs(int idx,int d) {
	if (v[idx] == 1)return;
	v[idx]  = 1;
	if (A[idx].size() == 0) {
		double sum = 0;
		totsum+= 1.0*w[idx]*pow(r*0.01+1,d)*p;
		return;
	}
	for (int i = 0; i < A[idx].size(); i++) 
		dfs(A[idx][i], d + 1);
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int root = 0;
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		if (t != 0)
			for (int j = 0; j < t; j++) {
				int tt;
				scanf("%d",&tt);
				A[i].push_back(tt);
				v[tt] = 1;
			}
		else
			scanf("%d", &w[i]);
	}

	for(int i=0;i<n;i++)
		if (v[i] == 0) {
			root = i;
			break;
		}
	memset(v,0,sizeof(v));
	dfs(root, 0);
	printf("%.1f", totsum);
	return 0;
}