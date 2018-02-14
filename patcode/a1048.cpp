
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

int A[101000];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int amount = 0;
	scanf("%d %d", &n,&amount);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	sort(A, A + n);
	int i = 0;
	int j = n - 1;
	
	bool flag = false;
	while (1)
	{
		int sum = A[i] + A[j];
		if (sum < amount)i++;
		else if (sum > amount)j--;
		else if (sum == amount) {
			flag = true;
			break;
		}
		if (i >= j)break;
	}
	if (!flag) {
		printf("No Solution");
	}
	else
		printf("%d %d",A[i],A[j]);
	//printf();

	return 0;
}