
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
int x[1010];
int m[1010];

int main() {
	freopen("./test.txt", "r", stdin);
	int cnt = 0;
	bool flag = false;

	while (scanf("%d %d", &x[cnt], &m[cnt]) != EOF) {

		x[cnt] *= m[cnt];
		m[cnt]--;
		
		if (m[cnt] < 0)break;
		
		cnt++;
		
	}
	flag = false;
	for (int i = 0; i < cnt; i++) {
		if (x[i] >= 0 || m[i] >= 0)flag = true;
	}
	if (!flag)
	{
		printf("0 0");
		return 0;
	}
	for (int i = 0; i < cnt; i++) {
	if(i!=cnt-1)
		printf("%d %d ", x[i], m[i]);
	else
		printf("%d %d", x[i], m[i]);
	}
	

	return 0;
}
