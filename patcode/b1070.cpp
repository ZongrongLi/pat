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
int A[10200] = {0};
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
	int sum = A[0];
	for (int i = 1; i < n; i++) {
		sum = (sum + A[i]) / 2;
	}
	cout << sum << endl;
	//printf();

	return 0;
}