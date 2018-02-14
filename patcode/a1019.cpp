
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

int A[1010] = {0};	
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int base = 0;
	scanf("%d %d", &n,&base);
	if (n == 0) {
		printf("Yes\n0");
		return 0;
	}
	int t = n;
	int cnt = 0;
	while (t != 0) {
		A[cnt++] = t % base;
		t = t / base;
	}
	bool flag = false;
	if ((cnt & 1 )== 0) {
		t= cnt / 2-1;
		int t1 = t + 1;
		
		while (t >= 0) {
		
			if (A[t] != A[t1]) {
				flag = true;
				break;
			}
			t1++;
			t--;
		}
	}

	if ((cnt & 1) == 1) {
		t = (cnt-1) / 2;
		int t1 = t;

		while (t >= 0) {
		
			if (A[t] != A[t1]) {
				flag = true;
				break;
			}
			t1++;
			t--;
		}
	}
	if (!flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	for (int i = cnt-1; i >=0; i--) {
		if(i!=0)
			printf("%d ", A[i]);
		else
			printf("%d", A[i]);

	
	}
	//printf();

	return 0;
}