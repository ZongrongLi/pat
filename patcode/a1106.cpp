
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

int n;
double p, r;
vector<int>A[100200];
int v[100200] = { 0 };
double lowest = 0x3fffffff;
int lowestcnt = 0;
void dfs(int idx,int d) {
	if (v[idx] == 1)return;
	v[idx] = 1;
	if (A[idx].size() == 0) {
		double price = p*pow(1.0 + r * 0.01, d);
	//	cout << "---" << price<<endl;
		if (lowest > price) {
			lowest = price;
			lowestcnt = 1;
		}
		else if (lowest == price)
			lowestcnt++;
		return;
	}
	for (int i = 0; i < A[idx].size(); i++)
		dfs(A[idx][i],d+1);
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d %lf %lf", &n,&p,&r);
	for (int i = 0; i < n; i++) {
		int ni;
		scanf("%d",&ni);
		if (ni == 0)continue;
		for (int j = 0; j < ni; j++) {
			int t;
			scanf("%d", &t);
			if(t!=0)
				A[i].push_back(t);
			v[t] = 1;
		}
	}
	int i = 0;
	int root;
	for (; i < n; i++)
		if (v[i] == 0)break;
	root = i;
	memset(v, 0, sizeof(v));
	dfs(root, 0);
	printf("%.4f %d",lowest, lowestcnt);

	return 0;
}
