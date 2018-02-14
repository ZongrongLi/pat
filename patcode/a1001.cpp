
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


int main() {
	freopen("./test.txt", "r", stdin);
	int a,b;
	scanf("%d %d", &a,&b);
	int c = a + b;
	char *s = new char[1010];;
	
	sprintf(s,"%d",c);
	if (c < 0) {
		cout << "-";
		s++;
	}
	//reverse(s, s + strlen(s));
	vector<char>ve;
	int cnt = 1;
	for (int i = strlen(s) - 1; i >= 0; i--) {
	
		ve.push_back(s[i]);
		if (cnt != 0 && ((cnt) % 3 == 0)&&i!=0)
			ve.push_back(',');
		cnt++;
	}
	for (int i = ve.size() - 1; i >= 0; i--)
		cout << ve[i];
	//printf();
//	delete [1010]s;
	return 0;
}