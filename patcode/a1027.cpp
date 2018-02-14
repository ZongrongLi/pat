
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

void printconvert(int k) {
	int a;
	int b;
	a = k % 13;
	b = k / 13;
	if (b >= 10) {
		cout << (char)(b-10 + 'A');
	}
	else
		cout << b;
	

	if (a >= 10) {
		cout << (char)(a-10 + 'A');
	}
	else
		cout << a;

	//printf("%d%c",a,b);
}
int main() {
	freopen("./test.txt", "r", stdin);
	int a, b, c;
	scanf("%d %d %d", &a,&b,&c);

	
	printf("#");
	printconvert(a);
	printconvert(b);
	printconvert(c);

	return 0;
}