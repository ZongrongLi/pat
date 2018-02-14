
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
	int a1 =0, a2=0, a3=0, a5=0;
	int sum4 = 0;
	float a4;
	int t;
	int flag = 1;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt4 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		
		if (t % 5 == 0 && (t & 1) == 0) {
			a1 += t;
			cnt1++;
		}
		if (t % 5 == 1) {
			a2 += flag * t;
			flag *= -1;
			cnt2++;
		}
		if (t % 5 == 2) {
			a3++;
		}
		if (t % 5 == 3) {
			sum4 += t;
			cnt4++;
		}
		if (t % 5 == 4) {
			if (a5 < t)a5 = t;
		}
	}
	a4 = 1.0*sum4 / cnt4;
	if (cnt1==0)
		printf("N ");
	else
		printf("%d ", a1);
	if (cnt2 == 0)
		printf("N ");
	else
		printf("%d ", a2);
	if (a3 == 0)
		printf("N ");
	else
		printf("%d ", a3);

	if (cnt4 == 0)
		printf("N ");
	else
		printf("%.1f ", a4);
	if (a5 == 0)
		printf("N");
	else
		printf("%d", a5);
	//printf("%d %d %d %.1f %d",a1,a2,a3,a4,a5);

	return 0;
}
