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
#include <set>
using namespace std;
int n = 0;
int tot = 0;
int fun(int n1, int b, int t, int n2) {
	if (b == 0) {
		if (n2 < n1)return t;
		else return -1 * t;
	}
	if (b == 1) {
		if (n2 > n1)return t;
		else return -1 * t;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d",&tot, &n);
	
	for (int i = 0; i < n; i++) {
		int n1, b, t, n2;
		cin >> n1 >> b >> t >> n2;
		int tmp = fun(n1, b, t, n2);
		if (t > tot) {
			printf("Not enough tokens.  Total = %d.\n", tot);
			continue;
		}
		tot += tmp;
		if (tot < 0)tot = 0;
		if (tmp > 0) {
			printf("Win %d!  Total = %d.\n", tmp, tot);
		}
		if (tmp<0)
			printf("Lose %d.  Total = %d.\n", -1 * tmp, tot);

		if (tot == 0) {
			cout << "Game Over.\n";
			break;
		}
	

	}
	//printf();

	return 0;
}


