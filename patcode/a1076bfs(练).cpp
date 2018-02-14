
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;

int A[2018][2018] = { 0 };

int n = 0, L = 0;
int cnt = 0;
int v[2018] = { 0 };
void bfs(int k) {
	queue<int>q;
	q.push(k);
	int last = k;
	int level = 0;
	v[k] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cnt++;
		
		for (int i = 1; i <= n; i++) {
			if (v[i] == 1)continue;
			if (A[t][i] != 0) {
				v[i] = 1;
				if(level <L)
				q.push(i);
			}
		}
		if (t == last) {
			level++;
			/*for (int i = n; i >= 0; i--)
				if (A[t][i] != 0 && v[i] == 1) { last = i; break; }*/
			if(!q.empty())
				last = q.back();
		}

	}
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			int t;
			scanf("%d", &t);
			A[t][i] = 1;
		}
	}


	int testcnt = 0;
	scanf("%d", &testcnt);
	for (int i = 0; i < testcnt; i++) {
		int temp;
		cnt = 0;
		memset(v, 0, sizeof(int) * 2018);
		scanf("%d", &temp);
		bfs(temp);
		cnt = cnt - 1 >= 0 ? cnt - 1 : 0;
		printf("%d\n", cnt);
	}


	//printf();

	return 0;
}
