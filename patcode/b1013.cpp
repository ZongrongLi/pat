
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool isprim(int k) {
	if (k == 1)return false;
	if (k <= 0)return false;
	int t = (int)sqrt(1.0*k);
	for (int i = 2; i <= t; i++) {
		if (k%i == 0)return false;
	}
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int m, n;
	isprim(6);
	scanf("%d %d", &m, &n);
	bool flag = true;
	int i = 0;
	int cnt = 0;
	while(++i) {
		if (isprim(i)) {
			cnt ++;
			if (cnt >= m) {
				if (flag) {
					printf("%d", i);
					flag = false;
				}
				else
					printf(" %d", i);
				if ((cnt - m + 1) % 10 == 0) {
					printf("\n");
					flag = true;
				}
			}
			
		}
		
		if (cnt == n)break;
	}
	//printf();

	return 0;
}