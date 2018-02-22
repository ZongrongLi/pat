
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

int c[2000] = { 0 };
int course[2000] = { 0 };
int isroot[2000] = { 0 };
int getroot(int k) {
	while (c[k]!=k)
		k = c[k];
	return k;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <=n; i++)c[i] = i;
	for (int i = 1; i <= n; i++) {
		int ni;
		scanf("%d: ",&ni);
		vector<int>ans;
		
		for (int j = 0; j < ni; j++) {
			int t;
			scanf("%d",&t);
			if (course[t] == 0)course[t] = i;
			int a = getroot(course[t]);
			int b = getroot(i);
			if (a != b)c[b] = a;
		}

	}

	for (int i = 1; i <= n; i++) {
		isroot[getroot(i)]++;
	}
	
	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		if (isroot[i] != 0)ans.push_back(isroot[i]);
	}
	printf("%d\n",ans.size());
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--)
		if(i!=0)
			printf("%d ",ans[i]);
		else 
			printf("%d", ans[i]);

	//printf();


	return 0;
}