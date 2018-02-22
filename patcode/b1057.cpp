
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
int toint(char c) {
	if (isupper(c))return c - 'A'+1;
	else if (islower(c))return c - 'a'+1;
	else return 0;
}
int main() {
	freopen("./test.txt", "r", stdin);

	char s[100200];
	cin.getline(s,100200);
	int len = strlen(s);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum+= toint(s[i]);
	}
	int cnt[2] = { 0 };
	while (sum != 0) {
		cnt[sum % 2]++;
		sum /= 2;
	}
	printf("%d %d",cnt[0],cnt[1]);

	return 0;
}