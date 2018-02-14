
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
float A[1010] = {0};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	int maxid = -1;
	int minid = 1010;
	for (int i = 0; i < n; i++) {
		int t1;
		float t2;
		scanf("%d %f", &t1,&t2);
		A[t1] += t2;
		if (maxid < t1)maxid = t1;
		if (minid > t1)minid = t1;
	}

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t1;
		float t2;
		scanf("%d %f", &t1, &t2);
		A[t1] += t2;
		if (maxid < t1)maxid = t1;
		if (minid > t1)minid = t1;
		//printf("--%f\n", A[t1]);
		
	}
	int cnt = 0;
	for (int i = maxid; i >= minid; i--)
		if (A[i] != 0)cnt++;
	printf("%d",cnt);
	for(int i=maxid;i>= minid;i--)
		if (A[i] != 0)
		{
				printf(" %d %.1f", i, A[i]);
		}

	return 0;
}
