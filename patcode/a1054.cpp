
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


int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d %d", &n,&m);
	int N = m * n;
	int t;
	scanf("%d",&t);
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		int tmp;
		scanf("%d",&tmp);
		if (tmp == t)cnt++;
		else cnt--;
		if (cnt < 0) {
			cnt = 0;
			t = tmp;
		}
	}
	printf("%d",t);

	return 0;
}