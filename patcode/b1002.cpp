
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
int a[10010] = { 0 };
char ss[10][100] = {
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};
int main() {
	freopen("./test.txt", "r", stdin);
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s.at(i) - '0';
	}
	char sss[10010];
	//itoa(sum, sss, 10);
	sprintf(sss,"%d",sum);
	for (int i = 0; i < strlen(sss); i++) {
		if (i != strlen(sss) - 1)
			cout << ss[sss[i] - '0'] << " ";
		else
			cout << ss[sss[i] - '0'];
	}

	//printf();

	return 0;
}