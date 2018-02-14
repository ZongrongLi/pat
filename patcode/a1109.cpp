
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
int n = 0,k;
class node {
public:
	int h;
	char na[20];
	bool operator <(const node&t) {
		if (this->h != t.h)return this->h < t.h;
		string s1 = this->na;
		string s2 = t.na;
			return s1 > s2;

	}
};
vector<node>vt;
vector<node>ans;
vector<node>ans1;
void cal(vector<node>&tmp) {
	int t = tmp.size() - 1;
	vector<node>tmp1;
	vector<node>tmp2;
	while (t >= 0)
	{
		tmp1.push_back(tmp[t]);
		t -= 2;
	}
	t = tmp.size() - 2;
	while (t >= 0)
	{
		tmp2.push_back(tmp[t]);
		t -= 2;
	}
	for (int i = tmp1.size()-1; i >=0; i--)
		//printf("%s ", tmp1[i].na);
		ans.push_back(tmp1[i]);

	for (int i = 0; i <tmp2.size(); i++)
		//printf("%s ", tmp2[i].na);
		ans.push_back(tmp2[i]);
	
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%s %d\n",t.na,&t.h);
		vt.push_back(t);
	}
	sort(vt.begin(), vt.end());
	int row = n / k;
	int idx = 0;
	int mod = n % row;
	int T = (vt.size() - row - mod);
	while (idx<T)
	{
		vector<node> tmp;
		for (int i = 0; i < row; i++) {
			tmp.push_back(vt[idx++]);
		}

		sort(tmp.begin(), tmp.end());
		cal(tmp);
		
		//printf("\n");

	}
	vector<node> tmp;
	while (idx<n)
	{
		tmp.push_back(vt[idx++]);
	}
	cal(tmp);
	//printf();
	
	reverse(ans.begin(), ans.end());
	 idx = 0;
	for (int i = 0; i < mod; i++)printf("%s ",ans[idx++].na);
	for (int i = 1; i <= n - mod; i++) {
		printf("%s", ans[idx++].na);
		if (i % row == 0)printf("\n");
		else printf(" ");
	}
	return 0;
}
