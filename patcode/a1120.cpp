
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
int A[10200] = {0};
int v[10200] = { 0 };
vector<int>vt;
int getdigit(int k) {
	int sum = 0;
	while (k!=0)
	{
		sum += k % 10;
		k /= 10;
	}
	return sum;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		int tt = getdigit(t);
		if (v[tt] == 0) {
			vt.push_back(tt);
			v[tt] = 1;
		}
	}
	sort(vt.begin(), vt.end());
	printf("%d\n",vt.size());
	for (int i = 0; i < vt.size(); i++) {
		if(i!=vt.size()-1)
		printf("%d ",vt[i]);
		else printf("%d", vt[i]);
	}
	//printf();

	return 0;
}
