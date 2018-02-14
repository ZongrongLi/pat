
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
int string2I(string s) {
	return (s[2] - 'A') *26 * 26 + (s[1]-'A') * 26 + s[0]-'A';
}
int A[2500][2500];
int haSh[20000] = {0};
int v[20000] = { 0 };
int tot = 0, thresh;

vector<string>i2s;

vector<string>node;

int n = 0;
int cnt = 0;

class TT {
public:
	string id;
	int cnt;
	bool operator<(const TT &t) {
		return this->id < t.id;
	}
};
vector<TT>ans;
int maxw =0;
int maxidx;
int totweight = 0;
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	cnt++;
	int weight = 0;
	for (int i = 0; i < tot; i++) {
		weight += A[k][i];
		if (A[k][i] == 0||v[i]==1)continue;
		dfs(i);
	}
	totweight += weight;
	if (cnt>2&&maxw < weight) {
		maxw = weight;
		maxidx = k;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d", &n,&thresh);
	for (int i = 0; i < n; i++) {
		char t1[5],t2[5];
		int tt;
		scanf("%s %s %d",t1,t2,&tt);
		int a, b;
		int I = string2I(t1);
		if (v[I] == 0) {
			v[I] = 1;
			node.push_back(t1);
			haSh[I] = node.size() - 1;

		}
		a = haSh[I];
		I = string2I(t2);
		if (v[I] == 0) {
			v[I] = 1;
			node.push_back(t2);
			haSh[I] = node.size() - 1;

		}
		b = haSh[I];
		A[a][b] += tt;
		A[b][a] += tt;	
	}
	tot = node.size();
	memset(v, 0, sizeof(v));
	//printf();
	for (int i = 0; i < tot; i++) {
		if (v[i] == 1)continue;
		maxw = -1;
		cnt = 0;
		totweight = 0;
		dfs(i);
		if (maxw != -1 &&totweight/2 >thresh) {
			TT t;
			t.id = node[maxidx];
			t.cnt = cnt;
			ans.push_back(t);
		}
	}

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%s %d\n",ans[i].id.c_str(),ans[i].cnt);
	
	return 0;
}
