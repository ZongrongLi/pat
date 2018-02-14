
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
using namespace std;


class node {
public:
	int idx;
	int rank;
	int w;
	node() {
		rank = 0;
	}
};
int A[2000];
int haSh[2000] = { 0 };
vector<node>vt;

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int diff;
	scanf("%d %d", &n,&diff);
	for (int i = 0; i < n; i++) 
		scanf("%d",&A[i]);

	for (int i = 0; i < n; i++) {
		int id;
		node t;
		scanf("%d", &id);
		t.w = A[id];
		t.idx = id;
		vt.push_back(t);
	}
	
	while (true)
	{
		int icnt = 0;
		int totcnt = 0;
		int maxidx = 0;
		int maxv = 0;
		for (int i = 0; i < vt.size(); i++) {
			if (vt[i].rank != 0)continue;
			icnt++;
			totcnt++;
			if (maxv < vt[i].w) {
				maxv = vt[i].w;
				maxidx = i;
			}
			if (icnt == diff) {
				vt[maxidx].rank = 65535;
				maxidx = 0;
				maxv = 0;
				icnt = 0;
			}

		}
		if (icnt != 0)
			vt[maxidx].rank = 65535;
		if (totcnt == 1) {
			haSh[vt[maxidx].w] = 1;
			vt[maxidx].rank = 1;
			break;
		}
		for (int i = 0; i < vt.size(); i++) {
			if (vt[i].rank == 65535)vt[i].rank = 0;
			else if (vt[i].rank == 0) {
				int r = (int)ceil(1.0*totcnt / diff) + 1;
				vt[i].rank = r;
				haSh[vt[i].w] = r;
			}
		}
		
	}
	for (int i = 0; i < n; i++) {
		if(i!=n-1)
			printf("%d ",haSh[A[i]]);
		else
			printf("%d", haSh[A[i]]);
	}
	return 0;
}