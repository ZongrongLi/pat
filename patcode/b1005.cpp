
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

int A[10010] = { 0 };
int H[10010] = { 0 };
vector<int>ans;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);	
	}
	
	for (int i = 0; i < n; i++) {
		int t = A[i];
		while (t!=1)
		{
			if (t % 2 == 0)t /= 2;
			else
				t = (t * 3 + 1) / 2;
			H[t] = 1;
		}

	}

	for (int i = 0; i < n; i++) {
		if (H[A[i]] == 0)
			ans.push_back(A[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size()-1; i >=0; i--) {
		if (i != 0)
			printf("%d ",ans[i]);
		else
			printf("%d",ans[i]);
	}
	
	//printf();

	return 0;
}