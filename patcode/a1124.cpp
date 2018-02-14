
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
int n = 0,m,s;
vector<string>vt;
vector<string>win;
bool iswined(string str) {
	bool flag = true;
	for (int i = 0; i < win.size(); i++) 
		if (str == win[i])return true;
	return false;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d", &n,&m,&s);
	for (int i = 0; i < n; i++) {
		char str[30]; 
		scanf("%s\n",str);
		
		vt.push_back(str);
	}
	//printf();
	int i = s-1;
	bool flag = false;
	while (i<vt.size())
	{
		while (iswined(vt[i]))i++;
		if (i >= vt.size())break;
		printf("%s\n",vt[i].c_str());
		win.push_back(vt[i]);
		i += m;
		flag = true;
	}
	if (!flag)
		printf("Keep going...");
	return 0;
}
