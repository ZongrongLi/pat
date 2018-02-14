
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

int st[2000];
int top = -1;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m,k;
	scanf("%d %d %d", &m,&n,&k);
	int c = 0;
	for (int i = 0; i < k; i++) {
		memset(st,0,sizeof(st));
		top = -1;
		c = 0;
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d",&t);
			if (top + 1 >= m)continue;
			while (st[top] != t)
			{
				if(c<n)
					c++;
				else break;
				st[++top] = c;
			} 
			if (t == st[top])top--;
		}
		if (top == -1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}