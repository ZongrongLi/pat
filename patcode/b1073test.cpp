#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int arr[105][10];
int numscore[105][5];

int tongji[105][10];
int m, n, mymax;

void read(int n) {
	for (int i = 1; i <= n; i++) {
		cin >> numscore[i][0];
		int j; char q;
		cin >> j >> j;
		numscore[i][1] = j;
		for (int c = 0; c<j; c++) { cin >> q; arr[i][q - 'a'] = 1; tongji[i][q - 'a'] = m; }
	}
}

int main()
{
	freopen("./test.txt", "r", stdin);
	cin >> m >> n;
	read(n);

	while (m--) {
		int ans = 0, stunum = 0;
		double sum = 0;
		char c;
		char kuo[10];
		for (int j = 1; j <= n; j++) {
			int key = 1;
			int ans = 0;
			cin >> kuo;
			stunum = kuo[1] - '0';
			for (int i = 0; i<stunum; i++) {
				cin >> c;
				if (arr[j][c - 'a']) {
					ans++;
					tongji[j][c - 'a']--;
				}
				else {
					key = 0;
					tongji[j][c - 'a']++;
				}
			}
			getchar();
			if (key) if (ans == numscore[j][1]) sum += numscore[j][0];
			else {
				sum += float(numscore[j][0]) / 2;
			}
		}
		printf("%.1lf\n", sum);
		sum = 0;
	}

	for (int i = 1; i <= n; i++)
		for (char m = 'a'; m <= 'e'; m++) {
			if (tongji[i][m - 'a'] > mymax) mymax = tongji[i][m - 'a'];
		}



	if (mymax > 0)for (int i = 1; i <= n; i++)
		for (char m = 'a'; m <= 'e'; m++) {
			if (tongji[i][m - 'a'] == mymax) printf("%d %d-%c\n", mymax, i, m);
		}
	else printf("Too simple\n");
}