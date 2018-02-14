
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

int n, m;
vector<int>A[200];
int v[200] = { 0 };
queue<int>q;
int maxcnt = 1;
int level = 1;
int maxlevel = 1;
void bfs() {
	q.push(1);
	int last = q.back();
	v[1] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		//if (A[t].size() == 0)continue;
		for (int i = 0; i < A[t].size(); i++) {
			if (v[A[t][i]] == 1)continue;
			v[A[t][i]] = 1;
			q.push(A[t][i]);
		}
		if (t == last) {
			if(!q.empty())
				last = q.back();
			level++;
			//cout << "---------" << q.size() << endl;
			if (maxcnt < q.size()) {
				maxcnt = q.size();
				maxlevel = level;
			}
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int id, ni;
		scanf("%d %d",&id,&ni);
		for (int j = 0; j < ni; j++){
			int t;
			scanf("%d",&t);
			A[id].push_back(t);
		}
	}
	//printf();
	bfs();
	
	printf("%d %d",maxcnt,maxlevel);
	return 0;
}
