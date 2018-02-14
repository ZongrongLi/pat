
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
int A[10000] = {0};
int v[10000] = { 0 };
bool isprim(int k) {
	if (k == 1)return false;
	if (k == 2)return false;
	int p = (int)sqrt(1.0*k);
	for (int i = 2; i <= p; i++)
		if (k%i == 0)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, -1, sizeof(A));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d",&t);
		A[t] = i;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		printf("%04d: ",t);
		if (v[t] == 1&&A[t]!=-1) {
			printf("Checked\n");
			continue;
		}
		v[t] = 1;
		if (A[t] == -1)
			printf("Are you kidding?");
		else if (A[t] == 1)
			printf("Mystery Award");
		else if (isprim(A[t]))
			printf("Minion");
		else
			printf("Chocolate");
		printf("\n");
	}

	return 0;
}
