#include "stdafx.h"
#include <stdio.h>

int main() {
	//freopen("./test.txt", "r", stdin);
	int a,b,d;
	
	scanf("%d %d %d", &a,&b,&d);
	a = a + b;
	int s[100];
	int top = -1;
	while (a != 0) {
		s[++top] = a % d;
		a = a / d;
	}
	if (top == -1)
		printf("0");
	while (top >= 0)
	{
		printf("%d",s[top--]);
	}
	//	printf("%d %d", maxI, max);
	return 0;
}