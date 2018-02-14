
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
#define INF 0x3fffffff
int n = 0,k;
string st;
int Hash[20000] = { 0 };
int hap[2018] = { 0 };
int A[2018][2018];
int num[2018] = {0};
vector<int>pre[2018];
int vis[2018] = { 0 };
int d[2018];
int head, rear;
vector<string>name;
class node {
public:
	int cost;
	int sumhappy;
	int n;
	vector<int>path;
	node() {
		cost = 0;
		sumhappy = 0;
		n = 0;
	}
	bool operator<(const node &t) {
		if (this->cost != t.cost)return this->cost < t.cost;
		if (this->sumhappy != t.sumhappy)return this->sumhappy > t.sumhappy;
		if (this->n != t.n)
			return this->n<t.n;
		return true;
	}
};

void dijtstra(int k) {
	fill(d, d + 2018, INF);
	d[k] = 0;
	num[k] = 1;
	for (int i = 0; i < n; i++) {
		int Min = INF;
		int u = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (A[u][v] == INF || vis[v] == 1)continue;
			if (d[v] > A[u][v] + d[u]) {
				d[v] = A[u][v] + d[u];
				pre[v].clear();
				pre[v].push_back(u);
				num[v] = num[u];
			}
			else if (d[v] == A[u][v] + d[u]) {
				pre[v].push_back(u);
				num[v] += num[u];
			}
		}
	}
}

vector<int>tmp;
vector<node>ansnode;
void dfs(int k) {
	tmp.push_back(k);
	if (k == Hash[head]) {
		int  thap = 0;
		for (int i = 0; i < tmp.size(); i++)
			thap += hap[tmp[i]];
		node t;
		t.cost = d[Hash[rear]];
		t.n = tmp.size();
		t.sumhappy = thap;
		t.path = tmp;
		ansnode.push_back(t);
		tmp.pop_back();
		return;
	}

	for (int i = 0; i < pre[k].size(); i++)
		dfs(pre[k][i]);
	tmp.pop_back();
}
int getInt(string s) {
	return (s[0]-'A') * 26 * 26 + (s[1]-'A') * 26 + s[2] -'A';
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 2018 * 2018, INF);
	scanf("%d %d", &n,&k);
	char str[5];
	scanf("%s\n",str);
	head = getInt(str);
	Hash[head] = 0;
	name.push_back(str);
	for (int i = 1; i <= n-1; i++) {
		scanf("%s %d",str,&hap[i]);
		Hash[getInt(str)] = i;
		name.push_back(str);
		if (strcmp(str, "ROM") == 0)rear = getInt(str);
	}
	for (int i = 0; i <k; i++) {
		char str1[5], str2[5];
		int c;
		scanf("%s %s %d\n",str1,str2,&c);
		int ia = Hash[getInt(str1)];
		int ib = Hash[getInt(str2)];
		A[ia][ib] = A[ib][ia] = c;

	}
	dijtstra(Hash[head]);
	//printf();
	memset(vis, 0, sizeof(vis));
	dfs(Hash[rear]);
	int minidx =0;
	for (int i = 1; i < ansnode.size(); i++) {
		if (ansnode[i] < ansnode[minidx])minidx = i;
	}
	node mnode = ansnode[minidx];
	printf("%d %d %d %d\n",num[Hash[rear]], mnode.cost, mnode.sumhappy, mnode.sumhappy/ (mnode.n-1));
	for (int i = mnode.path.size()-1; i >= 0; i--)
		if (i != 0)printf("%s->", name[mnode.path[i]].c_str());
		else printf("%s", name[mnode.path[i]].c_str());
	return 0;
}
