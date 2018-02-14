
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
int n = 0,m = 0;
int C1, C2;
int num[1010] = { 0 };
int A[1010][1010] = { 0 };
using namespace std;
class path {
public:
	vector<int>p;
	int w;
	path() {
		w = 0;
	}
	bool operator <(const path &T) {
		return this->w < T.w;
		
	}
};

int s[1010];
int top = -1;

int v[1010] = { 0 };
vector<path>ps;
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	s[++top] = k;

	if (k == C2) {
		path tp;
		tp.p.resize(top+1);
		for (int i = 0; i <= top; i++) {
			tp.p[i] = s[i];
		}
		for (int i = 0; i < top; i++) {
			tp.w += A[s[i]][s[i + 1]];
		}
		ps.push_back(tp);

		top--;
		v[k] = 0;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == 1)continue;
		if (A[k][i] == 0)continue;
		dfs(i);
	}
	top--;
	v[k] = 0;
}

int calchand(path p) {
	int sum = 0;
	for (int i = 0; i < p.p.size(); i++) {
		sum += num[p.p[i]];
	}
	return sum;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d %d", &n, &m,&C1,&C2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < m; i++) {
		int c1, c2, w;
		scanf("%d %d %d",&c1,&c2,&w);
		A[c1][c2] = w;
		A[c2][c1] = w;
	}
	dfs(C1);

	sort(ps.begin(), ps.end());
	if (ps.size() == 0) {
		printf("0 0");
	}
	else {
			int minx = ps[0].w;
			int  i = 0;
			int maxhand = 0;
			for (; i < ps.size(); i++) {
				if (ps[i].w != minx)break;
				int mxw = calchand(ps[i]);
				if (maxhand < mxw)maxhand = mxw;
			}
			printf("%d %d", i,maxhand);
	}
	//printf();

	return 0;
}
