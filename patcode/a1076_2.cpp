
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
int n = 0, l = 0;
int A[1010][1010] = { 0 };
int B[1010][1010];

using namespace std;
queue<int> q;
int cnt = 0;
int v[1010];
void bfs(int k) {
	int last;
	q.push(k);
	last = k;
	v[k] = 1;
	int level = 0;
	while (!q.empty()) {
		int  t =q.front();
		
		q.pop();
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (A[t][i] == 0 ||v[i] ==1)continue;
			v[i] = 1;
			if(level<l)
				q.push(i);
		}
		if (last == t) {
			level++;
			if(!q.empty())
				last = q.back();
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		int tcnt = 0;
		scanf("%d", &tcnt);
		for (int j = 0; j < tcnt; j++) {
			int t;
			scanf("%d",&t);
			A[t][i] = 1;
		}
	}

	int c = 0;
	scanf("%d",&c);
	for (int i = 0; i < c; i++) {
		cnt = 0;
		int t;
		memset(v, 0, sizeof(int)*1010);
		scanf("%d",&t);
		bfs(t);
		printf("%d\n", cnt-1);
	}
	//printf();

	return 0;
}