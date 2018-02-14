
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <utility>
#define LL long long
using namespace std;
const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 1010;
LL powP[MAXN], H1[MAXN] = { 0 }, H2[MAXN] = {0};

vector<pair<int, int> >pr1, pr2;

void init(int len) {
	powP[0] = 1;
	for (int i = 1; i <=len; i++) {
		powP[i] = (powP[i - 1] * P) % MOD;
	}

}
void calcH(LL H[],string &str) {
	H[0] = str[0];
	for (int i = 1; i < str.length(); i++) {
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}

int calSingleSubH(LL H[], int i, int j) {
	if (i == 0)return H[j];
	return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}
void calSubH(LL H[], int len, vector<pair<int, int> >&pr) {
	for(int i =0;i<len;i++)
		for (int j = i; j < len; j++) {
			int hashValue = calSingleSubH(H, i, j);
			pr.push_back(make_pair(hashValue, j - i + 1));
		}
}


int getMax() {
	int ans = 0;
	for (int i = 0; i<pr1.size(); i++)
		for (int j = i; j < pr2.size(); j++) {
			
			if (pr1[i].first == pr2[j].first) {
				ans = max(ans, pr1[i].second);
			}
		}

	return ans;
}
int main() {
	freopen("./test.txt", "r", stdin);
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	init(max(str1.length(), str2.length()));
	calcH(H1, str1);
	calcH(H2, str2);
	calSubH(H1,str1.length(),pr1);
	calSubH(H2, str2.length(), pr2);
	printf("ans = %d\n",getMax());
	return 0;

	return 0;
}
