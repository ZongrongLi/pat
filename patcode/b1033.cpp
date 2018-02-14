
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

int h[256] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	bool capslock = true;
	char s1[100010];
	char s2[100010];
	fgets(s1, 100010, stdin);
	fgets(s2, 100010, stdin);
	int len1 = strlen(s1);
	if (s1[len1 - 1] == '\n') {
		s1[strlen(s1) - 1] = '\0';
		len1--;
	}
	int len2 = strlen(s2);
	if (s2[len2 - 1 - 1] == '\n') {
		s2[strlen(s2) - 1] = '\0';
		len2--;
	}
	for (int i = 0; i < len1; i++) {
		if (islower(s1[i]))
			h[s1[i] - 'a' + 'A'] = 1;
		if(isupper(s1[i]))h[s1[i] - 'A' + 'a'] = 1;
		h[s1[i]] = 1;
		if (s1[i] == '+')capslock = false;
	}
	for (int i = 0; i < len2; i++) {
 		if (h[s2[i]] == 1)continue;
		if ((!capslock) && isupper(s2[i]))continue;
		printf( "%c",s2[i]);
	}

	return 0;
}