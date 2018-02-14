
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
int n = 0;
int A[10020];
class node {
public:
	int id;
	int es;
	int area;
	int num;
	double avarea;
	node() {
		num = 0;
		id = 0;
		es = 0;
		area = 0;
		avarea = 0.0;
	}
	bool operator <(const node &t) {
		if (this->avarea != t.avarea)return this->avarea > t.avarea;
		return this->id < t.id;
	}
};
int getroot(int k) {
	int t = k;
	while (k!=A[k])
		k=A[k];
	while (t != A[t]) {
		int tt = A[t];
		A[t] = k;
		t = A[tt];
	}
	return k;
}
vector<node>vt;
vector<node>ans;
int He[10000] = { 0 };
int Ha[10000] = { 0 };
int Hn[10000] = { 0 };
int v[10000] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	for (int i = 0; i < 10000; i++)A[i] = i;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		int a, b,c;
		scanf("%d %d %d",&a,&b,&c);
		t.id = a; 
		int l1 = getroot(a);
		if (b != -1) {
			int l2 = getroot(b);
			if(l2>l1)
				A[l2] = l1;
			else 
				A[l1] = l2;
			if (l1 > l2)l1 = l2;
		}
		
		if (c != -1) {
			int l3 = getroot(c);
			if (l1 < l3)
				A[l3] = l1;
			else
				A[l1] = l3;
			if (l1 > l3)l1 = l3;
		}
		int k;
		scanf("%d",&k);
		for (int i = 0; i < k; i++) {
			int tmp;
			scanf("%d",&tmp);
			int tt = getroot(tmp);
			if (tt < l1) {
				A[l1] = tt;
				l1 = tt;
			}
			else
				A[tt] = l1;
		}
		int es, area;
		scanf("%d %d",&es,&area);
		t.es = es;
		t.area = area;
		vt.push_back(t);
	}
	for (int i = 0; i < vt.size(); i++) {
		He[getroot(vt[i].id)] += vt[i].es;
		Ha[getroot(vt[i].id)] += vt[i].area;
	}
	for (int i = 0; i < 10000; i++) {
		Hn[getroot(i)] ++;
	}
	for (int i = 0; i < vt.size(); i++) {
		int id = getroot(vt[i].id);
		if (v[id] == 1)continue;
		node tmp;
		tmp.id = id;
		tmp.es += He[id];
		tmp.num = Hn[id];
		tmp.area = Ha[id];
		tmp.avarea = tmp.area*1.0 / tmp.num;
		ans.push_back(tmp);
		v[id] = 1;
	}
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].num,ans[i].es*1.0/ans[i].num,ans[i].avarea);
	}
	//printf();

	return 0;
}
