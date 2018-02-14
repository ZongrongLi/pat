#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define lowbit(x) x&(-x)
int getsum(int x) {
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		sum += i;
	}
	return sum;
}

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	int b = 15;
	b >>=1;
	getsum(2);
	//scanf("%d %d", &n, &total);
	/*for (int i = 0; i < n; i++) {

	}*/
	//printf();

	return 0;
}