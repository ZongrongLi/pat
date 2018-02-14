//1000 相乘 最高幂次可达2000！！！！！！！！！！
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class node {
public:
	int e;
	float c;
	node() {
		e = 0;
		c = 0;
	}
	node operator *(const node &T) {
		node tmp;
		tmp.e = this->e+T.e;
		tmp.c = this->c*T.c;
		return tmp;
	}
};
vector< node > a,b,ans;
float A[10010] = { 0 };

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %f", &t.e, &t.c);
		a.push_back(t);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %f", &t.e, &t.c);
		b.push_back(t);
	}

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			ans.push_back(a[i]*b[j]);
	int maxid = -1;
	int minid = 10010;
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		A[ans[i].e] += ans[i].c;
		if (maxid < ans[i].e)maxid = ans[i].e;
		if (minid > ans[i].e)minid = ans[i].e;
	}
	for (int i = maxid; i >= minid;i--) {
		if (A[i] != 0)cnt++;
	}
	printf("%d",cnt);
	for (int i = maxid; i >= minid;i--) {
		if (A[i] == 0)continue;
		printf(" %d %.1f",i,A[i]);
	}
	return 0;
}
