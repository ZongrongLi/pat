#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
class moon {
public:
	double total;
	double store;
	double div;
	bool operator <(moon &T) {
		return this->div > T.div;
	}
};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	double total = 0;
	scanf("%d %lf", &n,&total);
	moon a[1001];
	for (int i = 0; i < n; i++) {
		scanf("%lf",&a[i].store);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i].total);
		a[i].div = (double)a[i].total / a[i].store;
	}
	std::sort(a, a + n);
	int cur = 0;
	double sum = 0;
	while (1) {
		if (total > a[cur].store) {
			total -= a[cur].store;
			sum += a[cur].total;
		}
		else {
			sum += a[cur].div*total;
			break;
		}
		cur++;
	}
	printf("%.2f",sum);

	return 0;
}