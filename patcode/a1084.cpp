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

int h[2000] = {0};
int h1[2000] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	char s1[100], s2[100];
	fgets(s1,100,stdin);
	if(s1[strlen(s1) - 1] =='\n')
		s1[strlen(s1) - 1] = '\0';
	fgets(s2, 100, stdin);
	if (s2[strlen(s2) - 1] == '\n')
		s2[strlen(s2) - 1] = '\0';
	
	for (int i = 0; i < strlen(s2); i++) {
		if (s2[i] >= 'a' &&s2[i] <= 'z')s2[i] = s2[i] - 'a' + 'A';
		h[s2[i]] = 1;
	}
	for (int i = 0; i <strlen(s1); i++) {
		if (s1[i] >= 'a' &&s1[i] <= 'z')s1[i] = s1[i] - 'a' + 'A';
		if (h[s1[i]] == 0) {
			if (h1[s1[i] ] == 0) {			
				cout << s1[i];
				h1[s1[i]] = 1;
			}
		}
	}

	return 0;
}