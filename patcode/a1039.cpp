
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
#include <map>
using namespace std;

vector< vector<int> >A;
int toInt(char s[]) {
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum = sum * 26 + (s[i] - 'A');
	sum = sum * 10 + s[3] - '0';
	return sum;
}
int main() {
	int maxI = 26 * 26 * 26 * 10+1;
	int * hasH =  new int[maxI];
	A.resize(200010);
	memset(hasH, -1, sizeof(int)*maxI);
	freopen("./test.txt", "r", stdin);
	int n = 0 ,k;
	scanf("%d %d", &n,&k);
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int idx;
		int ni;
		scanf("%d %d\n", &idx, &ni);
		for (int j = 0; j < ni; j++) {
			//string tstr;
			//cin >> tstr;
			char tstr[2000];
			scanf("%s",tstr);
			//A[tstr] .push_back(idx);
		//	cout << toInt(tstr) << endl;
			if (hasH[toInt(tstr) ] == -1) {
				hasH[toInt(tstr)] = cnt;
				cnt++;
			}
			A[hasH[ toInt(tstr)]].push_back(idx);
		}
	}
	
	
	for (int i = 0; i < n; i++) {
		char tstr[2000];
		scanf("%s", tstr);
		printf("%s ", tstr);
		int idx = hasH[toInt(tstr)];
		if (idx == -1) {
			printf("0\n", tstr); continue;
		}
		int tt = A[idx].size();
		sort(A[idx].begin(),A[idx].end());
		
		printf("%d ",tt);
		for (int j = 0; j < tt; j++) {
			if (j != tt - 1)
				printf("%d ", A[idx][j]);
			else
				printf("%d", A[idx][j]);
		}
		
		printf("\n");
	}

	//printf();

	return 0;
}
