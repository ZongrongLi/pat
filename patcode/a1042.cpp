
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

int serial[58];
int ans[58];
int ans1[58];
#define MAXN 54
void print(int a[]) {
	for (int i = 1; i <= MAXN; i++) {
		char c = (char)(a[i] / 15);
		int d = a[i] % 15;
		if (i != MAXN)
			printf("%c%d ",c,d);
		else
			printf("%c%d", c, d);
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int flag = -1;
	scanf("%d", &n);
	for (int row = 1; row <= 4; row++) {
		int c;
		if (row == 1)c = (int)'S';
		if (row == 2)c = (int)'H';
		if (row == 3)c = (int)'C';
		if (row == 4)c = (int)'D';
		for (int i = 1; i <= 13; i++) {
			ans[(row - 1) * 13 + i] = c*15+i;
		}
	}

	for (int i = 1; i <= MAXN; i++) {
		scanf("%d",&serial[i]);

	}
	ans[53] = 'J' * 15 + 1;
	ans[MAXN] = 'J' * 15 + 2;
	for (int i = 0; i < n; i++) {
		flag *= -1;
		for (int j = 1; j <= MAXN; j++) {
			if (flag == 1) {
				ans1[serial[j]] = ans[j];
			}
			else {
				ans[serial[j]] = ans1[j];
			}
		}
	}
	if ((n & 1) == 0)
		print(ans);
	else
		print(ans1);
	//printf();

	return 0;
}
