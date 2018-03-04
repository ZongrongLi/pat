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
int A[100200];
int B[100200];
int V[100200];
vector<int>ans;
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, -1, sizeof(A));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		A[a] = b;
		A[b] = a;
	}

	scanf("%d", &n);
	memset(B, 0, sizeof(B));
	memset(V, 0, sizeof(V));
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		B[i] = t;
		V[t] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (A[B[i]] != -1&&V[A[B[i]]]==1)continue;
		ans.push_back(B[i]);

	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)printf("%05d ", ans[i]);
		else printf("%05d", ans[i]);

	}
	//printf();

	return 0;
}