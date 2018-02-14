
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

int A[100100] = {0};
vector<pair<int, int> > vt;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d" ,&A[i]);
	}

	bool flag = false;

	int i = 1, j = 1;
	int sum = 0;
	int minl = 0x3fffffff;
	while (j <= n+1)
	{
		if (sum < m) {
			sum += A[j++];
		}
		else if (sum == m) {
			printf("%d-%d\n", i, j-1);
			sum -= A[i];
			i++;
			flag  = true;
		}
		else if (sum > m) {
			sum -= A[i];
			i++;
		}
		if (sum > m &&minl > sum) {
			vt.clear();
			vt.push_back(make_pair(i, j-1));
			minl = sum;
		}
		else if (sum > m&&sum == minl) {
			vt.push_back(make_pair(i, j-1));
		}
	}
	if (!flag) {
		for(int i=0;i<vt.size();i++)
			printf("%d-%d\n", vt[i].first, vt[i].second);
	}


	return 0;
}
