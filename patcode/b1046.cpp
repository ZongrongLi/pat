
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
int pan(int a, int b, int c, int d) {
	int t = a + c;
	if (b == t && d != t)return 1;
	else if (d == t && b != t)return -1;
	else return 0;
}

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int a, b, c, d;
	int ac = 0, bc = 0;

	

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (pan(a, b, c, d) ==1)bc++;
		if (pan(a, b, c, d) == -1)ac++;
	}
	printf("%d %d",ac,bc);

	return 0;
}

