
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

int a1[100010];
int a2[100010];
int b1[100010];
int b2[100010];

bool cmp(int a, int b) {
	return a > b;
}
bool cmp1(int a, int b) {
	return a < b;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int nc = 0, np;;
	scanf("%d", &nc);
	int lena1=0, lena2=0, lenb1=0, lenb2=0;
	for (int i = 0; i < nc; i++) {
		int t;
		scanf("%d",&t);
		if (t > 0) {
			a1[i] = t;
			lena1++;
		}
		else {
			a2[i] = t;
			lena2++;
		}
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++) {
		int t;
		scanf("%d", &t);
		if (t > 0) {
			b1[i] = t;
			lenb1++;
		}
		else {
			b2[i] = t;
			lenb2++;
		}
	}
	sort(a1, a1 + nc,cmp);
	sort(b1, b1 + nc,cmp);
	sort(a2, a2 + np,cmp1);
	sort(b2, b2 + np,cmp1);
	int len1 = min(lena1, lenb1);
	int len2 = min(lena2,lenb2);
	int sum = 0;
	for (int i = 0; i <len1; i++) {
		int t = a1[i] * b1[i];
		if (t < 0)break;
		sum += t;

	}
	for (int i = 0; i <len2; i++) {
		int t = a2[i] * b2[i];
		if (t < 0)break;
		sum += t;

	}

	printf("%d",sum);

	return 0;
}
