
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

int A[100010];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}

	sort(A,A+n);
	bool flag = false;
	for (int j = n - 1; j >= 0; j--) {
		int c= upper_bound(A,A+j,m-A[j])-A;
		if (c != 0) {
			if (A[c - 1] != m - A[j])continue;
			cout << A[c-1] << " " << A[j];	
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "No Solution";
	//printf();

	return 0;
}
