
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


int reverseTOradix(int k,int d) {
	string s;
	while (k!=0)
	{
		s.push_back( (k%d)+'0' );
		k /= d;
	}
//	s.push_back('\0');
	int sum = 0;
	for (int i = 0; i <s.size(); i++)
		sum =sum*d + (s[i] - '0');
	return sum;
}


bool isprim(int  k) {
	if (k <= 1)return false;
	int t = (int)sqrt(1.0*k);
	for (int i = 2; i <= t; i++)
		if (k%i == 0)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	while (true)
	{
		int n, d;
		scanf("%d",&n);
		if (n < 0)break;
		scanf("%d",&d);
		int dec1 = reverseTOradix(n,d);
		if (isprim(n) && isprim(dec1))cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}
	
	//printf();

	return 0;
}
