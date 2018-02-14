
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
class node {
public:
	int data;
	int w;
};
vector<vector<int> > A;
vector<vector<int> > path;
int w[108];
int v[108] = { 0 };
int s[108];
int top = -1;
int n = 0, total = 0;
int nl = 0;
int dest = 0;
int pathcnt = 0;

int calcW(){
	int sum = 0;
	for (int i = 0; i <= top; i++) {
		sum += w[s[i]];
	}
	return sum;
}
void dfs(int k) {
	if (A[k].size() == 0) {
		s[++top] = k;
		int sum = calcW();
		if (sum == dest) {
			//´òÓ¡Êä³ö
			path[pathcnt].resize(top + 1);
			for (int i = 0; i <= top; i++)
				//printf("%d ",w[s[i]]);
				path[pathcnt][i] = w[s[i]];
			//printf("\n");
			pathcnt++;
		}
		top--;
		return;
	}
	
	v[k] = 1;
	s[++top] = k;
	for (int i = 0; i < A[k].size(); i++) {
		if (v[A[k].at(i)] == 1)continue;;
		dfs(A[k].at(i));
	}
	top--;
	v[k] = 0;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d", &n, &nl,&dest);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	int t = nl;
	A.resize(n + 1);
	path.resize(n + 1);
	while (t--) {
		int id, cnt = 0;
		scanf("%d %d", &id, &cnt);
		for (int i = 0; i < cnt; i++) {
			int t;
			scanf("%d", &t);
			A[id].push_back(t);
		}
	}
	dfs(0);
	sort(path.begin(), path.begin() + pathcnt);
	//printf();
	for (int i = pathcnt-1; i >= 0; i--) {
		for (int j = 0; j < path[i].size(); j++) {
			if(j!=path[i].size()-1)
			printf("%d ", path[i][j]);
			else
			{
				printf("%d", path[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
