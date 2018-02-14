
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

vector<int>vt;
vector<int>vtmp;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int t = (int)sqrt(1.0*n);
	int i = 2;
	int maxlong = 0;
	int divt = n;
	while (i<=t)
	{
		if (divt%i == 0) {
			vtmp.push_back(i);
			int c = divt / i;
			if (c > t && (c == i + 1)) {
				vtmp.push_back(c);
				//break;
			}
			divt /= i;
		}
		else {
			divt = n;
			i -= vtmp.size();
			vtmp.clear();
			
		}

		if (maxlong < vtmp.size()) {
			maxlong = vtmp.size();
			vt.clear();
			vt = vtmp;
		}
		i++;
	}
	if (vt.size() == 0) {
		cout << 1 << endl << n;
	}
	else
	{
		cout << vt.size() << endl;
		for (i = 0; i < vt.size(); i++) {
			if (i != vt.size() - 1)
				cout << vt[i] << "*";
			else
				cout << vt[i];
		}
	}
	
	//printf();

	return 0;
}
