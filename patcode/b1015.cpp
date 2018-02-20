
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
int n = 0,l,h;
class node {
public:
	string id;
	int v;
	int c;
	int sum;
	int rank;
	bool operator<(const node &t) {
		if (this->rank != t.rank)return this->rank > t.rank;
		if (this->sum != t.sum)return this->sum > t.sum;
		if (this->v != t.v)return this->v > t.v;
		return this->id < t.id;
	}
};
vector<node>vt;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d\n", &n,&l,&h);
	for (int i = 0; i < n; i++) {
		char s[10];
		int a, b;
		scanf("%s %d %d\n",s,&a,&b);
		node t;
		t.id = s;
		t.v = a;
		t.c = b;
		t.sum = a + b;
		if (a < l||b < l)continue;
		else if (a >= h && b >= h)t.rank = 4;
		else if (a >= l && a < h&&b >= l && b < h) {
			if (a >= b)t.rank = 2;
			else t.rank = 1;
		}
		else if (a < h&&a >= l && b >= h)t.rank = 1;
		else if (b >= l && b < h&&a >= h)t.rank = 3;
		vt.push_back(t);
	}
	printf("%d\n",vt.size());
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++) {
		printf("%s %d %d\n",vt[i].id.c_str(),vt[i].v,vt[i].c);
	}
	return 0;
}
