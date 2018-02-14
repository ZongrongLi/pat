
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
	scanf("%d", &n);
	int s = n / 10 % 10;
	int b = n / 100;
	int g = n % 10;
	for (int i = 0; i < b; i++) {
		cout << "B";
	}
	for (int i = 0; i < s; i++) {
		cout << "S";
	}
	for (int i = 1; i <= g; i++)
		cout << i;
	//printf();

	return 0;
}