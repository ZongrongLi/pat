
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

class node {
public:
	int perfect;
	int totals;
	int id;
	int rank;
	node(){
		id = 0;
		perfect = 0;
		totals = 0;
		rank = 0;
	}
	bool operator<(const node &t) {
		if(this->totals != t.totals)
			return this->totals > t.totals;
		if (this->perfect != t.perfect)
			return this->perfect >t.perfect;
		return this->id < t.id;
	}
};
int v[100100] = {0};
int vid[10010] = { 0 };
int f[8] = { 0 };
int score[10010][8] = {0};
vector<node> sortlist;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0 ,k,m;
	memset(score, 0, 8 * 10010 * sizeof(int));
	scanf("%d %d %d", &n,&k,&m);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &f[i]);
	}

	for (int i = 0; i < m; i++) {
		int id, tihao, grade;
		scanf("%d %d %d",&id,&tihao,&grade);
		//if (grade < 0)grade = 0;
		if (score[id][tihao] < grade)score[id][tihao] = grade;
		//if (grade == -1)score[id][tihao] = 0;
		v[id*10+tihao] = 1;
		
		if (vid[id] == 0 && grade != -1) {
			vid[id] = 1;
			node t;
			t.id = id;
			sortlist.push_back(t);
		}
	}

	for (int i = 0; i < sortlist.size(); i++) {
		int id = sortlist[i].id;
		int perfectcnt = 0;
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			if (score[id][i] == f[i])perfectcnt++;
			if (v[id * 10 + i] == 1) {
				sum += score[id][i];
			}
		}

		sortlist[i].perfect = perfectcnt;
		sortlist[i].totals = sum;
	}

	sort(sortlist.begin(), sortlist.end());
	int rank = 1;
	int grade = sortlist[0].totals;
	sortlist[0].rank = 1;
	
	for (int i = 0; i < sortlist.size(); i++) {
		if (i != 0) {
			if (sortlist[i].totals == sortlist[i - 1].totals) 		
				sortlist[i].rank = sortlist[i - 1].rank;
			else 
				sortlist[i].rank = i + 1;
		}
		printf("%d", sortlist[i].rank);

		int tid = sortlist[i].id;
		printf(" %05d %d",sortlist[i].id,sortlist[i].totals);
		for (int j = 1; j <= k; j++) {
			if (v[tid * 10 + j] == 0)printf(" -");
			else
				printf(" %d",score[tid][j]);
		}
		printf("\n");
	}
	//printf();

	return 0;
}
