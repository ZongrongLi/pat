
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


class node {
public:
	string id;
	int time;
	int state;

};

bool cmp1(node &a ,node &b) {
	if (a.id != b.id)return a.id < b.id;
	return a.time < b.time;
}

bool cmp2(node &a, node &b) {
	return a.time < b.time;
}
vector<node>A;

vector<node>B;

vector<string> maxtimev;
map<string, int> period;
int maxtime;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		node t;
		int a, b, c;
		char ts[1020];
		char ts1[10];
		scanf("%s %d:%d:%d %s",ts,&a, &b, &c,ts1);
		t.time = a * 3600 + b * 60 + c;
		t.id = ts;
		if (ts1[0] == 'i') {
			t.state = 0;
		}
		if (ts1[0] == 'o') {
			t.state = 1;
		}
		A.push_back(t);
		period[t.id] = 0;
	}

	sort(A.begin(), A.end(),cmp1);
	maxtime = -1;
	for (int i = 0; i < A.size()-1; i++) {
		if (A[i].id == A[i + 1].id) {
			if (A[i].state == 0 && A[i + 1].state == 1) {
				B.push_back(A[i]);
				B.push_back(A[i+1]);
				
				period[A[i + 1].id] +=A[i + 1].time - A[i].time;;
			}
		}
	}
	for (map<string, int>::iterator it = period.begin(); it != period.end(); it++) {
		if (maxtime < it->second) {
			maxtime = it->second;
			maxtimev.clear();
			maxtimev.push_back(it->first);
		}
		else if (maxtime == it->second)
			maxtimev.push_back(it->first);
	}
	sort(maxtimev.begin(),maxtimev.end());

	sort(B.begin(), B.end(), cmp2);
	int j = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d:%d:%d",&a,&b,&c);
		int t = a * 3600 + b * 60 + c;
		while (t>=B[j].time)
		{
			if (B[j].state == 0)cnt++;
			else cnt--;
			j++;
			if (j >= B.size())break;
		}
		printf("%d\n",cnt);
	}
	
	
	for (int i = 0; i < maxtimev.size(); i++)
		printf("%s ",maxtimev[i].c_str());
	printf("%02d:%02d:%02d", maxtime/3600,maxtime%3600/60,maxtime%60);

	return 0;
}



