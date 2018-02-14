
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
int A[12000] = {0};
int v[12000] = { 0 };
int getroot(int k) {
	int t = k;
	while (k != A[k])k=A[k];
	while (t!=A[t])
	{
		int tt = A[t];
		A[t] = k;
		t = A[tt];
	}
	return k;
}
void join(int a,int b) {
	a = getroot(a);
	b = getroot(b);
	if (a > b)swap(a, b);
	A[b] = a;
}
vector<int>vt;

int main() {
	freopen("./test.txt", "r", stdin);
	for (int i = 0; i < 12000; i++)A[i] = i;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d",&t);
		int a;
		if (t == 0)continue;
		scanf("%d",&a);
		if (v[a] == 0) {
			vt.push_back(a);
			v[a] = 1;
		}
		for (int j = 1; j < t; j++) {
			int b;
			scanf("%d",&b);
			join(a, b);
			if (v[b] == 0) {
				v[b] = 1;
				vt.push_back(b);
			}
		}
	}
	memset(v, 0, sizeof(v));
	int cnt = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (v[getroot(vt[i])] == 0) {
			cnt++;
			v[getroot(vt[i])] = 1;
		}
	}
	printf("%d %d\n",cnt,vt.size());
	scanf("%d",&n);
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a,&b);
		a = getroot(a);
		b = getroot(b);
		if (a == b)printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
