
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

bool isprim(int k) {
	if (k <= 1)return false;
	int sq = (int)sqrt(1.0*k);
	for (int i = 2; i <= sq; i++)
		if (k%i == 0)return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d %d", &m,&n);
	while (!isprim(m))m++;
	
	
	int *V = new int[m + 10];
	memset(V, 0, sizeof(V));
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		int c = t % m;
		int d = 1;
		int tmp = c;
		while (V[tmp] == 1)
		{
				tmp =(c + d * d)%m;
				d++;
				//if (tmp >= m)break;
				if(d >= m)break;
		}
		if (d>=m) {
			cout << "-";
			if (i != n - 1)cout << " ";
			continue;
		}
		V[tmp] = 1;
		cout << tmp;
		if (i != n - 1)cout << " ";

	}
	//printf();

	return 0;
}
