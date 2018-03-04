
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
class node {
public:
	int d;
	int ad;
	int next;
};
vector<node>vt1, vt2;
node A[100200];
int h, k;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d",&h, &n,&k);
	if (h == -1) {
		cout << "-1"<<endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %d %d",&t.ad,&t.d,&t.next);
		
		A[t.ad] = t;
	}
	int  p = h;
	while (p!=-1) {
		vt1.push_back(A[p]);
		p = A[p].next;
	}
	//printf();
	for (int i = 0; i < vt1.size(); i++) {
		if (vt1[i].d < 0)vt2.push_back(vt1[i]);
	}
	for (int i = 0; i < vt1.size(); i++) {
		if (vt1[i].d >= 0&&vt1[i].d<=k)vt2.push_back(vt1[i]);
	}
	for (int i = 0; i < vt1.size(); i++) {
		if (vt1[i].d > k)vt2.push_back(vt1[i]);
	}
	for (int i = 0; i < vt2.size(); i++) {
		if (i != vt2.size() - 1)
			printf("%05d %d %05d\n",vt2[i].ad,vt2[i].d,vt2[i+1].ad);
		else 
			printf("%05d %d -1\n", vt2[i].ad, vt2[i].d);
	}
	return 0;
}
