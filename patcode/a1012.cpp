
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
		int c;
		
		int id;
		bool operator <(const node &t) {
			return this->c > t.c;
}
};
char d[4] = {'A','C','M','E'};
vector<node>cp;
vector<node>math1;
vector<node>e;
vector<node>av;
int rankList[1000000][4] = {-1,-1,-1,-1};
int v[1000000] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	memset(rankList, 0,4000000*4);
	int n = 0,m=0;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		node t;
		int id;
		int a, b, c;
		scanf("%d %d %d %d",&id,&a,&b,&c);
		v[id] = 1;
		t.id = id;
		t.c = a;
		cp.push_back(t);
		t.c = b;
		math1.push_back(t);
		t.c = c;
		e.push_back(t);
		int average = (a + b + c);//-------------------ÉáÈë£¿
		t.c = average;
		av.push_back(t);
	}

	sort(cp.begin(), cp.end());
	sort(math1.begin(), math1.end());
	sort(e.begin(), e.end());
	sort(av.begin(), av.end());

	

	int cnt = 1;
	
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rankList[cp[i].id][1] = 1;
		}
		else {
			if (cp[i].c != cp[i - 1].c)
				rankList[cp[i].id][1] = i+1;
			else
				rankList[cp[i].id][1] = rankList[cp[i-1].id][1];
		}

	}
	
	 cnt = 1;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rankList[math1[i].id][2] = 1;
		}
		else {
			if (math1[i].c != math1[i - 1].c) {
				rankList[math1[i].id][2] = i+1;
			}
			else {
				rankList[math1[i].id][2] = rankList[math1[i-1].id][2];
			}
		}
	}

	cnt = 1;;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rankList[e[i].id][3] = cnt;
		}
		else {
			if (e[i].c != e[i - 1].c) {
				rankList[e[i].id][3] = i+1;
			}
			else {
				rankList[e[i].id][3] = rankList[e[i-1].id][3];
			}
		}
	}


	cnt = 1;;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rankList[av[i].id][0] = cnt;
		}
		else {
			if (av[i].c != av[i - 1].c) {
				rankList[av[i].id][0] = i+1;
			}
			else {
				rankList[av[i].id][0] = rankList[av[i-1].id][0];
			}
		}
	}
	//printf();
	while (m--)
	{
		int t = 0;
		scanf("%d", &t);
		int minN = 65535;
		int idx=-1;
		if (v[t] == 0) {
			printf("N/A\n");
			continue;
		}
		for (int i = 3; i >= 0; i--) {
			
			if (minN >= rankList[t][i]) {
				minN = rankList[t][i];
				idx = i;
			}
		}
		printf("%d %c\n",minN,d[idx]);
	}
	return 0;
}

