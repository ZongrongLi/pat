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
int n = 0, k;
class node {
public:
	char name[10];
	int score;
	bool operator<(const node&t){
		if(this->score!=t.score) return this->score < t.score;
		string s1 = this->name;
		string s2 = t.name;
		return s1 > s2;
	}
};
vector<node>vt;
vector<vector<node> >vt1;

vector<node>adjust(vector<node>&t) {
	deque<node>t1;
	deque<node>t2;
	vector<node>tmp;
	int cnt = 0;
	for (int i = t.size()-1; i >=0 ; i--) {
		cnt++;
		if (cnt % 2 == 1)t1.push_back(t[i]);
		else t2.push_back(t[i]);
	}
	while (!t2.empty()) {
		tmp.push_back(t2.back());
		t2.pop_back();
	}

	while (!t1.empty()) {
		tmp.push_back(t1.front());
		t1.pop_front();
	}
	return tmp;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d\n", &n,&k);
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%s %d\n",t.name,&t.score);
		vt.push_back(t);
	}
	sort(vt.begin(), vt.end());
	int  i = 0;
	vt1.resize(1);
	int row = n / k;
	while (i+row<=n)
	{
		if (vt1.back().size() < row)vt1.back().push_back(vt[i]);
		else {
			vector<node>tmp;
			tmp.push_back(vt[i]);
			vt1.push_back(tmp);
		}
		i++;
	}
	while (i < n) {
		vt1.back().push_back(vt[i++]);
	}
	//printf();
	for (int i = vt1.size()-1; i >=0 ; i--) {
		vector<node>ans = adjust(vt1[i]);
		for (int j = 0; j < ans.size(); j++) {
			if (j != ans.size() - 1)
				printf("%s ",ans[j].name);
			else 
				printf("%s\n", ans[j].name);
		}
	}
	return 0;
}