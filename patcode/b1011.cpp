
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


int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		int ans = a + b;
		if (a > 0 && b > 0 && ans < 0) {
			printf("Case #%d: true\n",i+1);
		}
		else if (a < 0 && b < 0 && ans>0) {
			printf("Case #%d: false\n", i + 1);
		}
		else if(a+b>c)
			printf("Case #%d: true\n", i + 1);
		else if(a+b<=c)
			printf("Case #%d: false\n", i + 1);
	}
	//printf();

	return 0;
}