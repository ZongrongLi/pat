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
int a, b, c, d, e;
int gcd(int x,int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d/%d %d/%d %d", &a,&b,&c,&d,&e);
	double l1 = (1.0*a) / (1.0*b);
	double l2 = (1.0*c) / (1.0*d);
	if (l1 > l2)swap(l1, l2);
	vector<int>ans;
	for (int i = 0; i <= e; i++) {
		double t = (1.0*i) / e;
		if (t > l1 && t < l2) {
			//printf("%d/%d",i,e);
			if (i == 0) {
				ans.push_back(i);
			}

			if (gcd(i,e)==1)
				ans.push_back(i);
			
		}
	}
	//printf();
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)
			printf("%d/%d ", ans[i], e);
		else 
			printf("%d/%d", ans[i], e);
	}
	return 0;
}