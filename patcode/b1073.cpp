
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
int n = 0,m;

vector< vector<char> >ans;
int idx = 0;
class node1 {
public:
	int id;
	char c;
	bool operator<(const node1&t) {
		if (this->id != t.id)return this->id < t.id;
		return this->c < t.c;
	}
};
int test(vector<char>&a, vector<char>&b) {
	int v[600] = { 0 };
	for (int i = 0; i < a.size(); i++)v[a[i]] = 1;
	bool flag = false;
	for (int i = 0; i < b.size(); i++) {
		if (v[b[i]] == 0) {
			flag = true;
			ans[idx].push_back(b[i]);
		}
		v[b[i]]++;
	}
	bool flag1 = false;
	for (int i = 0; i < a.size(); i++)
		if (v[a[i]] == 1) {
			flag1 = true;
			ans[idx].push_back(a[i]);
		}
	if (flag1)return -1;
	if (flag)return 0;
	return 1;
}

class node {
public:
	int score;
	vector<char> ans;
};

vector<node>vt;

int main() {
	freopen("./test.txt", "r", stdin);
	vt.resize(1);
	
	scanf("%d %d", &n,&m);
	ans.resize(m + 2);
	getchar();
	for (int i = 0; i < m; i++) {
		node tmp;
		int t, k;
		scanf("%d %d %d", &tmp.score, &t, &k);
		
		for (int j = 0; j < k; j++) {
			char tt;
			getchar();
			scanf("%c",&tt);
			tmp.ans.push_back(tt);
		}
		vt.push_back(tmp);
		getchar();
	}
	char ch;
	for (int i = 1; i <= n; i++) {
		vector<char>tmp;
		tmp.clear();
		idx = 1;
		double tot = 0.0;
		while ((ch = getchar()) != '\n') {
			if (ch == EOF)break;
			if (ch == ' ' || ch == '('||isdigit(ch))continue;
			if (ch == ')') {
				int flag = test(tmp,vt[idx].ans);
				if (flag == 0)tot += 1.0*vt[idx].score / 2;
				if (flag == 1)tot += vt[idx].score;
				tmp.clear();
				idx++;
				continue;
			}
			tmp.push_back(ch);
		}
		printf("%.1f\n", tot);
	}
	//printf();
	int Max = -1;
	vector<node1>ttt;
	for (int i = 1; i <= m; i++) {
		int c[200] = { 0 };
		for (int j = 0; j < ans[i].size(); j++) {
			c[ans[i][j]]++;
			if (Max < c[ans[i][j]]) {
				Max = c[ans[i][j]];
				ttt.clear();
				node1 tttt;
				tttt.id = i;
				tttt.c = ans[i][j];
				ttt.push_back(tttt);
			
			}
			else if (Max == c[ans[i][j]]) {
				node1 tttt;
				tttt.id = i;
				tttt.c = ans[i][j];
				ttt.push_back(tttt);
			}
		}

		
	}
	sort(ttt.begin(), ttt.end());
	for (int i = 0; i < ttt.size(); i++) {
		printf("%d %d-%c\n", Max, ttt[i].id, ttt[i].c);
	}
	if (ttt.size() == 0) {
		cout << "Too simple";
	}
	return 0;
}
