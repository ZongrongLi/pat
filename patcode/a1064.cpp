
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

int A[2000] = {0};
int B[2000];
int n;
int getr(int I) {
	if (2 * I + 1 <= n)return 2 * I + 1;
	else return -1;
}
int getl(int I) {
	if (2 * I <= n)return 2 * I;
	else return -1;
}
int cnt = 0;

void inorder(int I) {
	if (I == -1)return;
	inorder(getl(I));
	B[I] = A[cnt++];
	inorder(getr(I));
}

int main() {
	freopen("./test.txt", "r", stdin);
	memset(B, -1, 2000 * sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	sort(A,A+n);
	//printf();
	cnt = 0;
	inorder(1);
	for (int i = 1; i <= n; i++) {
		if (i != n)
			printf("%d ",B[i]);
		else 
			printf("%d", B[i]);
	}
	return 0;
}

