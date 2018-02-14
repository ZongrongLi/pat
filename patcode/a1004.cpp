
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

int n = 0, m;
vector<int>A[100200];
int cnt = 0;
int v[100200] = {0};
vector<int>ans;
queue<int>q;
void bfs() {
	q.push(1);
	v[1] = 1;
	int last = q.back();
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (A[t].size() == 0)cnt++;
		for (int i = 0; i < A[t].size(); i++) {
			if (v[A[t][i]] == 1)continue;
			v[A[t][i]] = 1;
			q.push(A[t][i]);
		}
		if (t == last) {
			ans.push_back(cnt);
			cnt = 0;
			if(!q.empty())
				last = q.back();
		}
	}
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int id ,ni;
		scanf("%d %d",&id, &ni);
		for (int j = 0; j < ni; j++) {
			int t;
			scanf("%d",&t);
			A[id].push_back(t);
		}
	}
	bfs();
	for(int i=0;i<ans.size();i++)
		if(i!=ans.size()-1)
			printf("%d ",ans[i]);
		else 
			printf("%d", ans[i]);

	return 0;
}
