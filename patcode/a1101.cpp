#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>

int a[100008];
int max[100008] = { 0 };
int s[1000008] = {0};
int top = -1;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	int M=0, m=1000000008;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > M)M = a[i];
		max[i] = M;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < m)m = a[i];
		if (a[i] >= max[i] && a[i] <= m) {
			s[++top] = a[i];
		}
	}
	if (top == -1) {//等于0的时候竟然要两个换行 醉了
		printf("0\n\n");
		return 0;
	}
		printf("%d\n ",top + 1);
		
		while(top>=0) {
			
			printf("%d", s[top]);
			if (top != 0)
				printf(" ");
			top--;
		}
	
	//printf();

	return 0;
}