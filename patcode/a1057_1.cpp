
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
int st[100200];
int block[100200] = {0};
int d[100200] = {0};
int top = -1;
int col = 0;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	col = sqrt(1.0*n);
	for (int i = 0; i < n; i++) {
		getchar();
		char s[30];
		scanf("%s",s);
		if (s[1] == 'o') {
			if (top == -1) {
				printf("Invalid\n");
				continue;
			}
			printf("%d\n",st[top]);
			block[st[top] / col]--;
			d[st[top]]--;
			top--;
		}
		if (s[1] == 'e') {
			if (top == -1) {
				printf("Invalid\n");
				continue;
			}
			int sum = 0;
			int c = 0;
			int mid = 0;
			if ((top + 1) % 2 == 0) {
				mid = (top + 1) / 2;
			}
			else
				mid = (top + 2) / 2;

			while (sum+block[c] <mid)
			{
				sum += block[c++];
			}
			
			int idx = (c*col);
			while (sum + d[idx] < mid)
			{
				sum += d[idx++];
			}
			printf("%d\n",idx);
		}
		if (s[1] == 'u') {
			int t;
			scanf("%d",&t);
			st[++top] = t;
			block[t / col]++;
			d[t]++;
		}
	}
	//printf();

	return 0;
}
