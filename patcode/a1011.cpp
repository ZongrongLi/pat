
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
using namespace std;

int A[10];
void print(int k) {
	if (k == 0)printf("W");
	else if(k==1)printf("T");
	else if (k == 2)printf("L");
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	float sum = 1;
	for (int i = 0; i < 3; i++) {
		float a, b, c;
		float t;
		scanf("%f %f %f ", &a, &b,&c);
		t = a > b ? a : b;
		t = t > c ? t : c;
		if (t == a)A[i] = 0;
		if (t == b)A[i] = 1;
		if (t == c)A[i] = 2;
		sum *= t;
	}
	sum *= 0.65;
	sum--;
	sum *= 2;
	for (int i = 0; i < 3; i++) {
		print(A[i]);
		printf(" ");
	}
	printf("%.2f",sum+0.005);
	//printf();

	return 0;
}