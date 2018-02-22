
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
using namespace std;
int n = 0;
char s[100200];
char y[100200];
char k[100200];
vector<vector<char> >ss;
vector<vector<char> >yy;
vector<vector<char> >kk;
vector<char>ans;
int printfc(int t,int tag) {
	if (tag == 0) {
		if (t < 1 || t >= ss.size())return -1;
		for (int i = 0; i < ss[t].size(); i++)
			ans.push_back(ss[t][i]);
	}
	if (tag == 1) {
		if (t < 1 || t >= yy.size())return -1;
		for (int i = 0; i < yy[t].size(); i++)
			ans.push_back(yy[t][i]);
	}
	if (tag == 2) {
		if (t < 1 || t >= kk.size())return -1;
		for (int i = 0; i < kk[t].size(); i++)
			ans.push_back(kk[t][i]);
	}
	return 0;
}
int main() {
	freopen("./test.txt", "r", stdin);
	cin.getline(s,100200);
	int len = strlen(s);
	vector<char>tmp;
	vector<char> nulL;
	ss.push_back(nulL);
	yy.push_back(nulL);
	kk.push_back(nulL);

	for (int i = 0; i < len; i++) {
		if(s[i]!='['&&s[i]!=']'&&s[i]!=' ')
			tmp.push_back(s[i]);
		if (s[i] == ']') {
			ss.push_back(tmp);
			tmp.clear();
		}
	}
	cin.getline(y, 100200);
	 len = strlen(y);
	for (int i = 0; i < len; i++) {
		if (y[i] != '['&&y[i] != ']'&&y[i] != ' ')
			tmp.push_back(y[i]);
		if (y[i] == ']') {
			yy.push_back(tmp);
			tmp.clear();
		}
	}
	cin.getline(k, 100200);
	 len = strlen(k);
	for (int i = 0; i < len; i++) {
		if (k[i] != '['&&k[i] != ']'&&k[i] != ' ')
			tmp.push_back(k[i]);
		if (k[i] == ']') {
			kk.push_back(tmp);
			tmp.clear();
		}
	}
	
	scanf("%d", &n);
	bool flag = false;
	
	for (int i = 0; i < n; i++) {
			ans.clear();
			int t;
			scanf("%d",&t);
			if (printfc(t, 0) == -1)flag = true;
		
			ans.push_back('(');
			scanf("%d", &t);
			if (printfc(t, 1) == -1)flag = true;
			scanf("%d", &t);
			if (printfc(t, 2) == -1)flag = true;

			scanf("%d", &t);
			if (printfc(t, 1) == -1)flag = true;

			ans.push_back(')');

			scanf("%d", &t);
			if (printfc(t, 0) == -1)flag = true;

			if (flag)printf("Are you kidding me? @\\/@");
			else
			{
				for (int i = 0; i < ans.size(); i++) {
					printf("%c",ans[i]);
				}
			}
			printf("\n");
	}
	//printf();

	return 0;
}