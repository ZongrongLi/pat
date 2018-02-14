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
int early = 8 * 3600;
int late = 17 * 3600;
int maxt = 3600;

int sum = 0;

class node {
public:
	int co;
	int wait;
	int end;
	node() {
		wait =co = -1;
		end = -1;
	}
	node(int a) {
		co = a;
		end = -1;
	}
	bool operator<(const node&t) {
		return this->co < t.co;
	}
};
vector<node> vt;
vector<node>q;
int getempty() {
	for (int i = 0; i < q.size(); i++)
		if (q[i].co == -1)return i;
	return -1;
}

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	q.resize(m);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d:%d:%d %d",&a,&b,&c,&d);
		if (d > maxt)d = maxt;
		int t = a * 3600 + b * 60 + c;
		
		if (t > late) continue;
		node tt;
		tt.co = t;
		if (d > 60)d = 60;
		tt.wait = d*60;
		vt.push_back(tt);
	}
	//printf();
	int idx = 0;
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].co < early) {
		sum += early - vt[i].co;
		vt[i].co = early;
		}
	}
	for (int s = early; s <=2*late ; s++) {
		
  		for (int j = 0; j < m; j++) {
			if (s >= q[j].end)
				q[j].co = -1;
		}
		int t = getempty();
		if(t!=-1&&idx<vt.size())
		while (getempty() != -1) {
			int t = getempty();
			if (s >= vt[idx].co) {
				q[t] = vt[idx++];
				
				q[t].end = s + q[t].wait;
				sum += s - q[t].co;
				if (idx >= vt.size())break;
			}
			else break;
			
		}
		
		
	}
	

	printf("%.1f",1.0*sum/idx/60);
	return 0;
}