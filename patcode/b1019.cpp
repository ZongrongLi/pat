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
#include <functional>
using namespace std;
int n = 0;

int main() {
	freopen("./test.txt", "r", stdin);
	char tmp[20];
	scanf("%d",&n);
	sprintf(tmp,"%04d",n);
	string s;
	s= tmp;
	string s1;
	
	while (true)
	{
		sort(s.begin(), s.end(), greater<char>());
		s1 = s;
		sort(s.begin(), s.end());
		int a = atoi(s1.c_str());
		
		int b = atoi(s.c_str());
		int c = a - b;
		if (c == 0) {
			printf("%04d - %04d = 0000\n", a, b);
			break;
		}
		char str[20];
		sprintf(str,"%04d",c);
		s.clear();
		s = str;
		printf("%04d - %04d = %04d\n",a,b,c);
		if (c == 6174)break;
	}
	//printf();

	return 0;
}
