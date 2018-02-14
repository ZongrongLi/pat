
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

int n = 0,l;
vector<int> A[2020];

queue<int> q;
int v[2020] = {0};
int cnt = 0;
void bfs(int k) {
	while (!q.empty())q.pop();
	q.push(k);
	v[k] = 1;
	k = 0;
	int level = 0;
	int last = q.back();
	
	while (!q.empty())
	{
		int t =q.front();
		q.pop();
		//cout << "---" << t<<endl;
		cnt++;
		for (int i = 0; i < A[t].size(); i++) {
			if (v[A[t][i]] == 1)continue;
			v[A[t][i]] = 1;
			q.push(A[t][i]);
		}
		if (t == last) {
			if(!q.empty())
				last = q.back();
			level++;
			if (level > l)break;
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, 0, sizeof(A));
	scanf("%d %d", &n,&l);
	for (int i = 1; i <= n; i++) {
		int ni;
		scanf("%d",&ni);
		for (int j = 0; j < ni; j++) {
			int t;
			scanf("%d", &t);
			A[t].push_back(i);
		}
	}

	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i++) {
		memset(v, 0, sizeof(v));
		int tt;
		scanf("%d", &tt);
		cnt = 0;
		bfs(tt);
		printf("%d\n",cnt-1);
	}
	//printf();

	return 0;
}
