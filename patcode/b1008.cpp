
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

int A[200];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	m = m % n;
	reverse(A, A + n - m );
	reverse(A + n - m , A+n);
	reverse(A, A + n);
	for (int i = 0; i < n; i++) {
		if(i!= n-1)
			printf("%d ",A[i]);
		else
			printf("%d",A[i]);
	}
	return 0;
}

