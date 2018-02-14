
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
int n = 0, m;
vector<int>male[10000];
vector<int>female[10000];
bool tot[10000][10000];
class node {
public:
	int f;
	int s;
	node(int a, int b) {
		f = a; s = b;
	}
	bool operator<(node&t) {
		if (this->f != t.f)return this->f < t.f;
		return this->s < t.s;
	}
};
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int a, b;
		a = atoi(s1.c_str());
		b = atoi(s2.c_str());
		if (s1[0]!='-'&& s2[0] !='-') {
			male[a].push_back(b);
			male[b].push_back(a);
		}
		if (s1[0] == '-'&& s2[0] == '-') {
			female[-1*a].push_back(-1*b);
			female[-1*b].push_back(-1*a);
		}

		tot[abs(a)][abs(b)] = tot[abs(b)][abs(a)] = true;
	}
	//printf();
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; i++) {
		int a, b;
		string s1, s2;
		cin >> s1 >> s2;
		
		a = atoi(s1.c_str());
		b = atoi(s2.c_str());
		//cin >> s1 >> s2;
		//scanf("%d %d",&a,&b);
		vector<node>ans;
		vector<int>*v1;
		vector<int>*v2;
		bool flag = false;
		if (s1[0]!='-' && s2[0] == '-') {
			v1 = &male[a];
			v2 = &female[-1*b];
			flag = true;
		}
		if (s1[0] == '-' && s2[0] != '-') {
			v1 = &female[-1*a];
			v2 = &male[b];
			flag = true;
		}
		if(s1[0] == '-' && s2[0] == '-') {
			v1 = &female[-1*a];
			v2 = &female[-1*b];
		}
		if (s1[0] != '-' && s2[0] != '-') {
			v1 = &male[a];
			v2 = &male[b];
		}
		int t = a * b;
		for(int u=0;u<v1->size();u++)
			for (int v = 0; v < v2->size(); v++) {
				if (tot[v1->at(u)][v2->at(v)] == true) {
					if ((!flag) && ( (v1->at(u) == abs(b))|| v2->at(v) ==abs(a)) )continue;
					ans.push_back(node(v1->at(u), v2->at(v) ) );
				}
		}
		

		printf("%d\n",ans.size());
		sort(ans.begin(), ans.end());
		for (int j = 0; j < ans.size(); j++) {
			printf("%04d %04d\n",ans[j].f,ans[j].s);
		}
	}
	return 0;
}