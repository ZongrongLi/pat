
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



bool iscorrect(string s) {
	if (s[0] == 'T')return false;
	string tmp;
	int i = 0;
	int a=0, b=0, c=0;
	i = 0;
	while (s[i++] == 'A')a++; 
	if (i>s.size())return false;
	while (s[i++] == 'A')b++;
	if (i>s.size())return false;
	while (s[i++] == 'A')c++;

	while (b>1)
	{
		c -= a;
		b--;
	}
	if(b==1 &&a==c)return true;
	return false; 
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (iscorrect(s)) 
			cout << "YES" << endl;
		else
			cout << "NO"<<endl;
		
	}

	return 0;
}
