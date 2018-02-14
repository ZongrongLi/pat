
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

int h[200] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		h[t]++;
	}
	int  m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d",&t);
		if (i != m-1)
			printf("%d ",h[t]);
		else
			printf("%d", h[t]);
	}
	//printf();

	return 0;
}