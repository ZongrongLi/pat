#include "stdafx.h"
#include <stdio.h>
int A[100001] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	int n,col=0,row=0;
	char c;
	scanf("%d %c\n", &n,&c);
	col = n;
	row= (int)( ((float)n)/2 + 0.5);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i != 0 && i != (row - 1)) {
				if (j != 0 && j != col - 1)
					printf(" ");
				else
					printf("%c", c);
			}
			else
				printf("%c", c);
			
		}
		printf("\n");
	}
//	printf("%d %d", maxI, max);
	return 0;
}