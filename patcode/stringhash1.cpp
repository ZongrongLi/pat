
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <utility>
#include <xutility>
#include <string>
using namespace std;

#define LL long long
const int P = 10000019;
const int MOD = 1000000007;
LL  *h1 = new LL[1010], *h2 = new LL[1010];
string str1, str2;

LL powP[1010];;


void initPow() {
	powP[0] = 1;
	for (int i = 1; i < 1010; i++) {
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}
void calcH(LL H[],string str) {
	H[0] = str.at(0) ;

	for (int i = 1; i < str.length(); i++) {
		H[i] = (H[i - 1] * P + (str[i] ) )%MOD;
	}
}


LL calcsubhash(LL H[],int i,int j) {
	if (i == 0)return H[j];

	return (((H[j] - H[i - 1] * powP[j - i + 1]) % MOD) + MOD) % MOD;

}

int maxL = 0;


vector< pair<int, int> >pr1, pr2;
void calcvector(LL H[],string str, vector< pair<int, int> > &pr) {
	int len = str.length();
	
	for(int i=0;i<len;i++)
		for (int j = i+1; j < len; j++) {
			int a= calcsubhash(H, i, j);
			pr.push_back(make_pair(a, j - i + 1));
		}
}


void getmax() {
	int len1 = pr1.size();
	int len2 = pr2.size();
	
	for (int i = 0; i<len1; i++)
		for (int j = i + 1; j < len2; j++){
			if (pr1[i].first == pr2[j].first) {
				if (maxL < pr1[i].second) {
					maxL = pr1[i].second;
				}
			}
		}
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	//scanf("%d %d", &n, &total);
	
	getline(cin,str1);
	getline(cin,str2);
	initPow();

	
	memset(h1, 0, sizeof(h1));
	memset(h2, 0, sizeof(h2));

	

	calcH(h1, str1);
	calcH(h2, str2);

	calcvector(h1,str1,pr1);
	calcvector(h2, str2, pr2);
	
	getmax();
	printf("%d\n",maxL);
	//printf();

	return 0;
}
