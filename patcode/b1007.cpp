
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
int A[100010] = {0};
bool isprim(int k) {
	if (k <= 1)return false;
	int t = (int)sqrt(1.0*k);
	for (int i = 2; i <= t; i++) {
		if (k%i == 0)return false;
	}
	return true;
}



int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int cnt = 0;
	A[0] = 0;
	A[1] = 0;
	A[2] = 1;
	for (int i = 3; i <= n; i++) {
		if (isprim(i)) {
			A[i] = 1;
			if (A[i] == 1 && A[i - 2] == 1)cnt++;
		}
	}
	cout << cnt;

	return 0;
}
