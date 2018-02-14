
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

#define LL long long
int v[100010] = { 0 };
vector<LL> vt;
int main() {
	freopen("./test.txt", "r", stdin);
	LL n = 0;
	scanf("%lld", &n);
	if (n == 1) {
		cout << "1=1";
		return 0;
	}
	LL sq = (LL)sqrt(1.0*n);
	LL t = n;
	for (int i = 2; i <= sq; i++) {
		while (t%i==0)
		{
			if (v[i] == 0)
				vt.push_back(i);
			v[i]++;
			t /= i;
		}
	}
	if(t!=1)
		vt.push_back(t);
	v[t] = 1;
	cout << n<<"=";
	for (int i = 0; i < vt.size(); i++) {
		if(v[vt[i]]>1)
			cout << vt[i] << "^" << v[vt[i]] ;
		else 
			cout << vt[i];
		if (i != vt.size() - 1)
			cout << "*"; 
	}
	//printf();

	return 0;
}
