
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

int pan(char a,char b) {
	if (a == b)return 0;
	if (a == 'C' &&b == 'J')return 1;
	if (a == 'C' &&b == 'B')return -1;
	if (a == 'J'&&b == 'C')return -1;
	if (a == 'J'&&b == 'B')return 1;
	if (a == 'B'&&b == 'C')return 1;
	if (a == 'B'&&b == 'J')return -1;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d\n", &n);
	int cnta = 0,cntb=0;
	int maxa[1010] = { 0 };
	int maxb[1010] = { 0 };
	for (int i = 0; i < n; i++) {
		char a, b;
		scanf("%c %c\n",&a,&b);
		int c = pan(a, b);
		if (c > 0) {
			cnta++;
			maxa[a]++;
		}
		else if (c < 0) {
			cntb++;
			maxb[b]++;
		}
	}
	printf("%d %d %d\n",cnta, n - cnta - cntb,cntb);
	printf("%d %d %d\n", cntb, n - cnta - cntb,cnta);
	char maxc = 'J';
	int maxt = 0;
	if (maxt <= maxa['J']) {
		maxt = maxa['J'];
		maxc = 'J';
	}
	if (maxt <= maxa['C']) {
		maxt = maxa['C'];
		maxc = 'C';
	}

	if (maxt <= maxa['B']) {
		maxt = maxa['B'];
		maxc = 'B';
	}
	printf("%c ",maxc);

	 maxc = 'J';
	 maxt = 0;
	if (maxt <= maxb['J']) {
		maxt = maxb['J'];
		maxc = 'J';
	}
	if (maxt <= maxb['C']) {
		maxt = maxb['C'];
		maxc = 'C';
	}

	if (maxt <= maxb['B']) {
		maxt = maxb['B'];
		maxc = 'B';
	}
	printf("%c", maxc);

	return 0;
}
