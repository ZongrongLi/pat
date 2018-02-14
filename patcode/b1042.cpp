
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

int a[2018] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	char s[2018];
	fgets(s,2018,stdin);
	int len = strlen(s);
	if (s[len - 1] == '\n') {
		s[len - 1] = '\0';
		len--;
	}
	int maxi = -1;
	char maxc =300;
	for (int i = 0; i < len; i++) {
		if (!isalpha(s[i]))continue;
		if (isupper(s[i]))s[i] = tolower(s[i]);
		a[s[i]]++;
		if (maxi < a[s[i]]) {
			maxi = a[s[i]];
			maxc = s[i];
		}
		else if (maxi == a[s[i]]) {
			if (maxc >s[i]) {
				maxc = s[i];
			}
		}
	}
	cout << maxc << " " << maxi;
	//printf();

	return 0;
}