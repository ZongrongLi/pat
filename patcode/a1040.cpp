
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
int len = 0;
char str[2000];
int getI(int id) {
	int cnt1 = 1;
	int i = id;
	int j = id;
	while (true)
	{
		i--; j++;
		if (i < 0 || j >= len)break;
		if (str[i] != str[j])break;;
		
		cnt1 += 2;
	}

	int cnt2 = 0;
	 i = id-1;
	 j = id;
	while (true)
	{
		if (i < 0 || j >= len)break;
		if (str[i] != str[j])break;;
		i--; j++;
		cnt2 += 2;
	}

	int cnt3 = 0;
	i = id;
	j = id+1;
	while (true)
	{
		if (i < 0 || j >= len)break;
		if (str[i] != str[j])break;;
		i--; j++;
		cnt3 += 2;
	}
	int Max = cnt1;
	if (Max < cnt2)Max = cnt2;
	if (Max < cnt3)Max = cnt3;
	return Max;
}
int main() {
	freopen("./test.txt", "r", stdin);

	
	fgets(str,2000,stdin);
	len = strlen(str);
	if (str[len - 1] == '\n') {
		str[len - 1] = '\0';
		len--;
	}
	int Max = -1;
	for (int i = 0; i < len; i++) {
		int t = getI(i);
		if (Max < t)Max = t;
	}
	printf("%d",Max);

	return 0;
}

