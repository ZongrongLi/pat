
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

char A[100][100] = {' '};
int V[100][100] = { 0 };
int p= 0;
int n1,n2;
char s[100];
void dfs(int a,int b) {
	A[a][b] = s[p++];
	V[a][b] = 1;
	if (a + 1 < n1 &&V[a+1][b]==0 )dfs(a + 1, b);
	else if (b + 1 < n2 &&V[a][b+1] == 0)dfs(a, b + 1);
	else if (a - 1 >= 0&&V[a - 1][b] == 0)dfs(a - 1, b);
}
int main() {
	freopen("./test.txt", "r", stdin);
	for(int i=0;i<100;i++)
	fill(A[i], A[i]+100, ' ');
	scanf("%s", s);

	int l = strlen(s);
	//n1 = (l + 2) / 3;
	//n2 = l+2-n1*2;
	n1 = -1;
	for (int i = 1; i < l; i++) {
		int n11=i, n22;
		n22 = l + 2 - 2 * n11;
		if (n11 > n22)continue;
		if (n1 < n11)n1 = n11;
	}
	n2 = l + 2 - 2 * n1;
	 dfs(0, 0);
	 for (int i = 0; i < n1; i++) {
		 for (int j = 0; j < n2; j++)
			 printf("%c", A[i][j]);
		 cout << endl;
	 }
	
	return 0;
}