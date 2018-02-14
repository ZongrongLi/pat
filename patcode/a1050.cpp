
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

int h[2018] = {0};
char s1[100010];
char s2[100010];
int main() {
	freopen("./test.txt", "r", stdin);
	fgets(s1, 100010, stdin);
	fgets(s2, 100010, stdin);
	
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (s1[len1 - 1] == '\n') {
		s1[len1-1] = '\0';
		len1--;
	}
	if (s2[len2 - 1] == '\n') {
		s2[len2-1] = '\0';
		len2--;
	}
	for (int i = 0; i < len2; i++) {
		h[s2[i]] = 1;
	}

	for (int i = 0; i < len1; i++) {
		if (h[s1[i]] == 1) continue;
		printf("%c",s1[i]);
	}
	//printf("\n");
	return 0;
}