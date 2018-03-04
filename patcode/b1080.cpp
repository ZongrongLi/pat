
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
	string id;
	int pro;
	int mid;
	int fe;
	int G;
node():pro(-1),mid(-1),fe(-1),G(-1){}
bool operator <(const node &t) {
	if (this->G != t.G)return this->G > t.G;
	return this->id < t.id;
}
};
map<string, int> mp;
vector<node>vt;
int main() {
	freopen("./test.txt", "r", stdin);
	vt.resize(1);
	scanf("%d %d %d",&p,&m, &n);
	getchar();
	for (int i = 0; i < p; i++) {
		char s[50];
		int t;
		
		
		scanf("%s %d", s, &t);
		//if (t < 200)continue;
		node tmp;
		tmp.id = s;
		tmp.pro = t;
		if (mp[s] == 0) {
			vt.push_back(tmp);
			mp[s] = vt.size()-1;
		}
		getchar();
	}
	//printf();
	for (int i = 0; i < m; i++) {
		char s[50];
		int t;
		scanf("%s %d", s, &t);
		if (mp[s] == 0)continue;
		vt[mp[s]].mid = t;
		getchar();
	}

	for (int i = 0; i < n; i++) {
		char s[50];
		int t;
		scanf("%s %d", s, &t);
		if (mp[s] == 0)continue;
		node &tmp = vt[mp[s]];
		tmp.fe = t;
		if (tmp.mid > tmp.fe) {
			tmp.G = (int)((0.4*tmp.mid + 0.6*tmp.fe) + 0.5);
		}
		else tmp.G = tmp.fe;
		getchar();
	}
	vector<node>ans;
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].pro < 200||vt[i].G<60)continue;
		if (vt[i].fe == -1 || vt[i].G == -1 && vt[i].pro == -1)continue;
		ans.push_back(vt[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		node &t = ans[i];
		cout <<t.id<<" "<< t.pro << " " << t.mid << " " << t.fe << " " << t.G << endl;

	}
	return 0;
}
