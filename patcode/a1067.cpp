
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
int H[100010] = { 0 };
int n = 0;
int minidx = 0;
void swap(int k) {
			
			A[H[0]] = k;
			A[H[k]] = 0;
			
			int tmp = H[k];
			H[k] = H[0];
			H[0] = tmp;
}
//bool isdone() {
//	
//	for (int i = 0; i < n; i++) {
//		if (A[i]!=i)return false;
//	}
//	return true;
//}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
		H[A[i]] = i;
	}
	int cnt = 0;
	int k = 0;
	while (true)
	{
		if (H[0] == 0) {
			if (k<=n-1) {
				for (; k < n; k++)
					if (A[k] != k) {
						swap(k);
						break;
					}
			}
			else
				break;
		}
		else
			swap(H[0]);
		cnt++;
		/*if (cnt == 10)break;
		for (int i = 0; i < n; i++)
			cout << A[i];
			cout<< endl;*/
	}
	printf("%d",cnt-1);

	return 0;
}
