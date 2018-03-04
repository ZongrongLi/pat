//读题 独一无二颜色的那个像素点
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
#include <map>
using namespace std;
int n = 0,m,tot;
int A[2000][2000];
int diff(int a, int b) {
	return abs(a - b);
}
map<int, int>mp;
bool test(int a,int b) {
	bool flag = true;
	//if (a == 1 || b == 1 || a == m || b == n)return false;
	if (a - 1 >= 1 && diff(A[a][b], A[a - 1][b]) <= tot)flag = false;
	if (b - 1 >= 1 && diff(A[a][b], A[a][b-1]) <= tot)flag = false;
	if(a + 1 <= m && diff(A[a][b], A[a + 1][b]) <= tot)flag = false;
	if (b + 1 <= n && diff(A[a][b], A[a][b+1]) <= tot)flag = false;
	if (a - 1 >= 1&&b-1>=1 && diff(A[a][b], A[a - 1][b-1]) <= tot)flag = false;
	if (a + 1 <=m &&b-1>=1 &&diff(A[a][b], A[a + 1][b-1]) <= tot)flag = false;
	if (a + 1 <=m && b + 1 <=n &&diff(A[a][b], A[a + 1][b + 1]) <= tot)flag = false;
	if (a - 1 >= 1 && b + 1 <= n&& diff(A[a][b], A[a - 1][b + 1]) <= tot)flag = false;
	return flag;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d", &n,&m,&tot);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			mp[A[i][j]]++;
		}
	}
	int cnt = 0;
	int ci=0, cj =0;
	int mc;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			if (mp[A[i][j]] == 1 && test(i, j)) {
				cnt++; ci = i; cj = j;
				mc = A[i][j];
				//cout << ci << " " << cj << " " << endl;
			}
	}
	if (cnt == 1) {
		printf("(%d, %d): %d", cj, ci, mc);
	}
	else if (cnt > 1)
		cout << "Not Unique";
	else if (cnt == 0) {
		cout << "Not Exist";
	}
	//printf();

	return 0;
}