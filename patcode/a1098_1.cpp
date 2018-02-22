
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
int A[2000] = { 0 };
int B[2000] = { 0 };
int C[2000] = { 0 };
bool ise(int a[], int b[]) {
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])return false;
	return true;
}
void print() {
	for (int i = 1; i <= n; i++)
		if (i != n)
			printf("%d ", A[i]);
		else
			printf("%d", A[i]);
}

void adjust(int k) {
	int ni = k / 2;
	for (int v = ni; v > 0; v--) {
		int tmp = A[v];
		int i = v;
		int j = v * 2;
		while (j<=k)
		{
			if (j + 1 <= k && A[j] < A[j + 1])j++;
			if (A[j] > tmp) {
				A[i] = A[j];
				i = j;
				j *= 2;
			}
			else break;
		}
		A[i] = tmp;
	}
}
int main() {
	freopen("./test.txt", "r", stdin);
	bool flag = false;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		C[i] = A[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 2; i <= n; i++) {
		sort(A, A + i + 1);
		if (flag) {
			printf("Insertion Sort\n");
			print();
			return 0;
		}
		if (ise(A, B))flag = true;
	}
	
	printf("Heap Sort\n");
	memcpy(A, C, sizeof(C));
	adjust(n);
	for (int i = n; i >= 2; i--) {
		swap(A[1],A[i]);
		adjust(i-1);
		if (flag) {
			print();
			return 0;
		}
		if (ise(A, B))flag = true;
	}
	//printf();

	return 0;
}
