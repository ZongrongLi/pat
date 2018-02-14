//floyd»á³¬Ê±£¡£¡£¡£¡£¡£¡
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
#include <set>
using namespace std;
int n = 0,m,k,ds,N;

int A[1080][1080];
#define INF 0x3fffffff
void floyed() {
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
			for (int v = 1; v <= N; v++) {
				//if (A[j][v] == INF)continue;
				if (A[j][i] + A[i][v] < A[j][v]) {
					A[j][v] = A[j][i] + A[i][v];
				}
			}
}

class node {
public:
	int mind;
	double sum;
	int idx;
	node() {
		mind = 0;
		sum = 0.0;
		idx = -1;
	}
	bool operator <(const node &t) {
		if (this->mind != t.mind)return this->mind > t.mind;
		if (this->sum != t.sum)return this->sum < t.sum;
		return this->idx < t.idx;
	}
};
vector<node>ans;
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 1080 * 1080, INF);
	scanf("%d %d %d %d\n", &n,&m,&k,&ds);
	N = n + m;
	for (int i = 0; i < k; i++) {
		char s1[20], s2[20];
		int t;
		scanf("%s %s %d\n",s1,s2,&t);
		int a, b;
		if (s1[0] != 'G') 
			a =atoi(s1);
		else 
			a = atoi(s1 + 1)+n;
		if (s2[0] != 'G')
			b = atoi(s2);
		else
			b = atoi(s2 + 1)+n;
		A[a][b] = A[b][a] = t;
	}
	floyed();


	for (int i = n + 1; i <= N; i++) {
		int Min = 0x3fffffff;
		bool flag = false;
		double sum = 0.0;
		for (int j = 1; j <= n; j++) {
			if (ds < A[i][j])flag = true;
			if (Min > A[i][j])Min = A[i][j];
			sum += A[i][j];
		}
		if (!flag) {
			node t;
			t.idx = i;
			t.mind = Min;
			t.sum = sum;
			ans.push_back(t);
		}
	}
	if (ans.size()==0) {
		printf("No Solution");
		return 0;
	}

	//sort(ans.begin(), ans.end());
	node minnode = ans[0];
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] < minnode)minnode = ans[i];
	}
	printf("G%d\n",minnode.idx -n);
	printf("%.1f %.1f", 1.0*minnode.mind, minnode.sum/n);
	//printf();

	return 0;
}
