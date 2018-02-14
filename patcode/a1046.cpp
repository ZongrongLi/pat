
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
int dist[100010] = { 0 };
int pathdist[100010] = { 0 };

int n = 0,m=0;
void nexta(int &k) {
	k++;
	if (k > n)k = 1;
}

void pre(int &k) {
	k--;
	if (k < 1)k = n;
}

int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&dist[i]);
		sum += dist[i];
		pathdist[i] = pathdist[i - 1] + dist[i-1];
	}
	scanf("%d", &m);
	int sum1 = 0;
	int sum2 = 0;
	int l, r;
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		sum1 = sum2 = 0;
		sum1 = pathdist[b] - pathdist[a];
		sum2 = sum - sum1;
		
		printf("%d\n", sum1<sum2? sum1 : sum2);
		

	}
	

	return 0;
}
