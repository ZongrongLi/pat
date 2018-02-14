#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>


int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	int a[60];
	int cnt = 10;
	while (cnt--)scanf("%d", &a[n++]);
	int i = 1;
	while (a[i++] == 0)i++;
	printf("%d",i-1);
	a[i-1]--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++)
			printf("%d",i);
	}
	
	//printf();

	return 0;
}