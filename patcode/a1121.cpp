
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
int n = 0;
int v[100020] = { 0 };
int v1[100020] = { 0 };
vector<int>vt;
vector<int>ans;
int main() {
	freopen("./test.txt", "r", stdin);
	memset(v, -1, sizeof(v));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a] = b;
		v[b] = a;
	}
	//printf();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v1[a] = 1;
		vt.push_back(a);
	}
	for (int i = 0; i < vt.size(); i++) {
		if (v1[v[vt[i]]] == 1)continue;
		ans.push_back(vt[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)
			printf("%05d ", ans[i]);
		else
			printf("%05d", ans[i]);
	}
	return 0;
}
