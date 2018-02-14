#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>

char a[100008];
int b[100008] = {0};
int c[100008] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%s",a);
	int len = strlen(a);
	if (a[0] == 'P')b[0] = 1;
	if (a[len - 1] == 'T')c[len - 1] = 1;
	for (int i = 1; i < len; i++) {
		if (a[i] == 'P')b[i] = b[i - 1] + 1;
		else b[i] = b[i - 1];
	}
	for (int i = len - 2; i >= 0; i--) {
		if (a[i] == 'T')c[i] = c[i +1] + 1;
		else c[i] = c[i + 1];
	}
	long long sum = 0;
	for (int i = 1; i < len; i++) {
		if (a[i] == 'A') {
			sum += b[i] * c[i];
		}
	}
	printf("%d",sum% 1000000007);

	return 0;
}