//ÀÛ¼ÓµÄÔ¶³¬¹ý long long
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
#define  LL long long
bool ispalin(LL k) {
	char s[20];
	sprintf(s,"%lld",k);
	int i = 0;
	int j = strlen(s) - 1;
	while (i<j)
	{
		if (s[i] != s[j])return false;
		i++; j--;
	}
	return true;
}
LL reverseInt(LL k) {
	char s[20];
	sprintf(s, "%lld", k);
	reverse(s, s + strlen(s));
	LL t =atoll(s);
	return t;
}
int main() {
	freopen("./test.txt", "r", stdin);
	LL n = 0;
	int c = 0;
	scanf("%lld %d", &n,&c);
	LL t = n;
	int cnt = 0;
	while (!ispalin(t)&&cnt<c)
	{
		t = t + reverseInt(t);
		cnt++;
	}
	cout << t << endl << cnt;
	//printf();

	return 0;
}
