
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


int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	char c;
	scanf("%d %c", &n,&c);
	int ji = 1;
	int cnt = 0;
	int sum = 1;
	while (sum<=n) {
	
		ji += 2;
		sum += ji * 2;
	
	}
	
	sum -= ji*2;
	ji -= 2;
	for (int i = ji; i >= 1; i -= 2) {
		for (int j = 0; j < cnt; j++)printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
		cnt++;
	}
	cnt-=2;
	for (int i = 3; i <= ji; i += 2) {
		for (int j = 0; j < cnt; j++)printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
		cnt--;
	}
	cout << n - sum;
	return 0;
}