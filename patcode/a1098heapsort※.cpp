
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
int n = 0;
int A[2000] = { 0 };
int B[2000] = { 0 };
int C[2000] = { 0 };
void adjust(int r) {
	int ni = r / 2;
	for (int i = ni; i >= 1; i--) {
		int tmp = A[i];
		int k = i;
		int j = k * 2;
		while (j<=r)
		{
			if (j+1<=r&&A[j] < A[j + 1])j++;
			if (A[j] > tmp) {
				A[k] = A[j];
				k = j;
				j = j * 2;
			}
			else break;
		}
		A[k] = tmp;
	}
}
bool ise(int a[],int b[]) {
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])return false;
	return true;
}
void print() {
	for (int i = 1; i <= n; i++)
		if (i != n)
			printf("%d ", A[i]);
		else
			printf("%d",A[i]);
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&A[i]);
		C[i] = A[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	//printf();
	adjust(n);
	bool flag = false;
	for (int i = n; i >= 1; i--) {
		swap(A[1], A[i]);
		adjust(i-1);
		if (flag) {
			printf("Heap Sort\n");
			print();
			break;
		}
		if (ise(A, B))flag = true;
	}
	if (!flag) {
		memcpy(A, C, sizeof(int)*(n+2));
		for (int i = 2; i <= n; i++) {
			sort(A,A+i+1);
			if (flag) {
				printf("Insertion Sort\n");
				print();
				break;
			}
			if (ise(A, B))flag = true;
		}
	}
	return 0;
}