
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

int a[100010] = {0};
int c[100010];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	
	scanf("%d", &n);
	int m ;
	for (int i = 0; i < n; i++) {
		
		scanf("%d",&c[i]);
		a[c[i]]++;
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (a[c[i]] == 1) {
			printf("%d",c[i]);
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "None";
	//printf();

	return 0;
}