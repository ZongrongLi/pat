
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
#include <map>
using namespace std;
int n = 0,p,m;
class node {
public:
	int p;
	int m;
	int f;
	int G;
	string id;
	node() {
		m = -1;
		p = f = -1;
		G = -1;
	}
	bool operator<(node &t) {
		if (t.G != this->G)return this->G > t.G;
		return this->id < t.id;
	}
};
map<string, node>mp;
vector<node>ans;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d\n",&p,&m, &n);
	for (int i = 0; i < p; i++) {
		int d;
		char s[30];
		scanf("%s %d\n",s,&d);
		mp[s].id = s;
		mp[s].p = d;
	}

	for (int i = 0; i < m; i++) {
		int d;
		char s[30];
		scanf("%s %d\n", s, &d);
		mp[s].m = d;
	}

	for (int i = 0; i < n; i++) {
		int d;
		char s[30];
		scanf("%s %d\n", s, &d);
		mp[s].f = d;
		if (mp[s].m > mp[s].f)
			mp[s].G = (int)(0.4*mp[s].m + 0.6*mp[s].f+0.5);
		else 
			mp[s].G = mp[s].f;
		
	}
	//printf();
	map<string, node>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
 		if((*it).second.p>=200&&(*it).second.G>=60&& (*it).second.G <= 100&& (*it).second.G!=-1)
			ans.push_back((*it).second);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].p, ans[i].m,ans[i].f,ans[i].G);
	return 0;
}