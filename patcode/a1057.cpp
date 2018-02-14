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
int st[100200] = { 0 };
int block[100200] = { 0 };
int v[100200] = { 0 };
int row = 0;
int col = 0;
int top = -1;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	char str[20];
	row = (int)(sqrt(1.0*100200) +0.5);
	col = (int)sqrt(1.0 * 100200) ;
	
	for (int i = 0; i < n; i++) {
		memset(str, 0, sizeof(str));
		scanf("%s",str);
		if (str[1] == 'o') {
			if (top == -1) {
				printf("Invalid\n");
				continue;
			}
			block[st[top] / col]--;
			v[st[top]]--;
			printf("%d\n",st[top--]);
		
		}
		if (str[1] == 'e') {
			if (top == -1) {
				printf("Invalid\n");
				continue;
			}
			int mid;
			if ((top + 1) % 2 == 1) {
				mid = (top) / 2 +1;
			}
			else
				mid = (top+1) / 2 ;

		
			int sum = 0;
			int i;
			for (i = 0; i < row; i++) {
				sum += block[i];
				if (sum >= mid)break;
			}
			if (sum >= mid)sum-=block[i];
			int u = i;
			for (i = 0; i < col; i++) {
				int t = col * u + i;
					sum += v[t];
					if (sum >= mid) {
						printf("%d\n", t);
						break;
					}
				//}
			}
			
		}
		if (str[1] == 'u') {
			int t;
			scanf("%d",&t);
			st[++top] = t;
			block[t/col]++;
			v[st[top]]++;
		}
	}
	//printf();

	return 0;
}