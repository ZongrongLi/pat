
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
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	char s1[2018];
	char s2[2018];
	fgets(s1,2018,stdin);
	fgets(s2, 2018, stdin);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (s1[len1 - 1] == '\n') {
		s1[len1 - 1] = '\0';
		len1--;
	}
	if (s2[len2 - 1] == '\n') {
		s2[len2 - 1] = '\0';
		len2--;
	}
	
	for (int i = 0; i < len1; i++) {
		h[s1[i]]++;
	}
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < len2; i++) {
		h[s2[i]]--;
		if (h[s2[i]] < 0) {
			flag = true;
			cnt++;
		}

	}

	if (!flag) {
		printf("Yes %d",len1 - len2);
	}
	else {
		printf("No %d", cnt);
	}
	//printf();

	return 0;
}
