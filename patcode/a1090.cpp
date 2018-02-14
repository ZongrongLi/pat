
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
double maxprice = -1;
int maxcnt = 0;
void dfs(int idx, int d) {
	if (v[idx] == 1)return;
	v[idx] = 1;
	if (A[idx].size() == 0) {

		double price = p * pow(1 + r * 0.01, d);
		if (maxprice < price) {
			maxprice = price;
			maxcnt = 1;
		}
		else if (maxprice == price)
				maxcnt++;
		return;
	}
	for (int i = 0; i < A[idx].size(); i++)
		dfs(A[idx][i], d + 1);
}
int main() {
	freopen("./test.txt", "r", stdin);
	int root;
	scanf("%d %lf %lf", &n,&p,&r);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		if (t != -1)
			A[t].push_back(i);
		else
			root = i;
	}
	//printf();
	dfs(root,0);
	printf("%.2f %d",maxprice,maxcnt);
	return 0;
}
