#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>

int a[5] = { 1,2,3,4,5 };
int cnt = 0;
void fun(int idx) {
	if (idx == 4) {
		for (int i = 0; i < 5; i++)printf("%d",a[i]);
		printf("\n");
		cnt++;
		return;
	}
	
	for (int i = idx; i < 5; i++) {
		int tmp = a[idx];
		a[idx] = a[i];
		a[i] = tmp;
		fun(idx + 1);
		tmp = a[idx];
		a[idx] = a[i];
		a[i] = tmp;
		
	}
}
int main() {
	//freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	//scanf("%d %d", &n, &total);

	//printf();
	fun(0);
	printf("%d",cnt);
	return 0;
}