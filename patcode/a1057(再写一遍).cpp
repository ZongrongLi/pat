
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <functional>//greater µÄ±êÊ¶·û
using namespace std;
int top = -1;
int st[100010];
int xhash[100010] = { 0 };
int block[100010] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);

	int  sum = 0;
	int row = (int)(sqrt(100010) + 0.5);
	int col = (int)(sqrt(100010));
	for (int i = 0; i < n; i++) {
		
		//printf("---------%d\n",i);
		char s[20];
		scanf("%s",s);
		int t = 0;
		int u = 0, v = 0;
		int cnt = 0;

		switch (s[1]) {
		case 'o':
			if (top == -1) {
				printf("Invalid\n");
				break;
			}
			t = st[top--];
			xhash[t] --;
			block[t / col] --;
			printf("%d\n", t);
			break;
		case 'e':
			sum = 0;
			cnt = 0;
			if (top == -1) {
				printf("Invalid\n");
				break;
			}
			if ((top + 1) % 2 == 0)
				t = (top + 1) / 2 - 1;
			else
				t = (top) / 2;
			t++;
			while (sum + block[u] < t) {
				sum += block[u++];
			}
			cnt = u * row;
			while (sum + xhash[cnt] < t) {
				sum += xhash[cnt++];
			}
			printf("%d\n",cnt);
			break;
		case 'u':
			scanf("%d",&t);
			st[++top] = t;
			xhash[t]++;

			block[t / col]++;
		}
	}
	//printf();

	return 0;
}
