
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include<string>
#include <iostream>
using namespace std;
map<string, int>name2num;

int A[2080][2080] = {0};//ÁÚ½Ó¾ØÕó
int v[2080] = { 0 };
int n;
int e;


class node {
public:
	string id ;
	int num;
	node() {
		num = 0;
	}
	bool operator <(const node &T) {
		return this->id < T.id;
	}
};
int maxid[2080] = { 0 };

int gangs[2080] = {0};
int topgang = -1;
string num2str[2080];



int cnt = 0;
int totalweight = 0;
int gangsweight[2080] = { 0 };
void dfs(int key) {
	if (v[key] == 1)return;
	v[key] = 1;
	cnt++;
	int weight = 0;
	for (int i = 0; i < e; i++) {
		if (v[i] == 1)continue;
		if (A[key][i] != 0) {
			dfs(i);
		}
	}

	for (int i = 0; i < e; i++) {
			weight += A[key][i];
			weight += A[i][key];
	}
	totalweight += weight;
	if (gangs[topgang ] < weight) {
		gangs[topgang ] = weight;
		maxid[topgang] = key;
	}
}
node rec[2080];
int  cnts[2080];
int main() {
	freopen("./test.txt", "r", stdin);
	n = 0;
	int k= 0;
	scanf("%d %d", &n, &k);
	int mcnt = 0;
	for (int i = 0; i < n; i++) {
		string ts1,ts2;
		int tw;
		cin >> ts1 >> ts2 >> tw;
		if (name2num.find(ts1) ==name2num.end()){
			name2num[ts1]= mcnt;
			num2str[mcnt++] = ts1;
		}
		if (name2num.find(ts2) == name2num.end()) {
			name2num[ts2] = mcnt;
			num2str[mcnt++] = ts2;
		}
		A[name2num[ts1]][name2num[ts2]] = tw;
	}
	e = mcnt;
	
	for (int i = 0; i < mcnt; i++) {
		if (v[i] == 0) {
			topgang++;
			totalweight = 0;
			cnt = 0;
		}
		dfs(i);
		cnts[topgang] = cnt;
		gangsweight[topgang] = totalweight/2;
		
	}
	
	cnt = 0;
	for (int i = 0; i <= topgang; i++) {
		if (gangsweight[i] <= k)continue;
		if (cnts[i] <= 2)continue;
		node t;
		t.id = num2str[maxid[i]];
		t.num = cnts[i];
		rec[cnt++] = t;
	}
	printf("%d\n",cnt);
	sort(rec, rec + cnt);
	for (int i = 0; i <cnt; i++) {
		printf("%s %d\n",rec[i].id.c_str(), rec[i].num);
	}
	return 0;
}
