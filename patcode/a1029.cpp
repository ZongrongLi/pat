
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


#define LL long long
LL A[2000100];

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld",&A[i]);
		
	}
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%lld", &A[n+i]);
	}
	sort(A, A + m + n);
	int mid = (m + n + 1) / 2;
	cout << A[mid-1];
	

	//printf();

	return 0;
}
