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
int getnum(int k) {
	int sum = 0;
	while (k) {
		sum += k % 10;
		k /= 10;
	}
	return sum;
}
int H[10200] = {0};
vector<int>ans;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		t = getnum(t);
		if (H[t] == 0) {
			ans.push_back(t);
			H[t] = 1;
		}
	}
	//printf();
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)printf("%d ",ans[i]);
		else printf("%d", ans[i]);
	}
	return 0;
}