
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
#include <functional>
using namespace std;
int n = 0;
vector<int>vt;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vt.push_back(t);
	}
	
	sort(vt.begin(), vt.end(),greater<int>());
	while (vt.size()>1)
	{
		int tmp1 = vt.back(); vt.pop_back();
		int tmp2 = vt.back(); vt.pop_back();
		tmp1 = (tmp1 + tmp2) / 2;
		vt.push_back(tmp1);
	}
	
	printf("%d",vt[0]);

	return 0;
}
