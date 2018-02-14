
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
#include<map>
using namespace std;

class DateM {
public:
	int day;
	int M;
	int h;
	int m;
	DateM() {
		h = 0;
		m = 0;
		day = 0;
		M = 0;
	}

	bool operator <(const DateM &t) {
		int a = this->day * 60*24 + this->h * 60 + this->m;
		int b = t.day * 60 * 24 + t.h * 60 + t.m;
		return a < b;
	}
	bool operator ==(const DateM &t) {
		return (this->h == t.h)  && (this->day == t.day ) && (this->m == t.m);
	}
	int operator -(const DateM &t) {
		int a = this->day * 60 * 24 + this->h * 60 + this->m;
		int b = t.day * 60 * 24 + t.h * 60 + t.m;
		return a - b;
	}

	DateM& operator ++() {
		m++;
		if (m == 60) {
			m = 0;
			h++;
		}
		if (h == 24) {
			h = 0;
			day++;
		}

		return *this;
	}
};
class node {
public:
	string name;
	bool state;
	DateM d;
	node() {
		state = false;
	}
	bool operator <(const node &t) {
		if (this->name != t.name) return this->name < t.name;
		return this->d < t.d;
	}
};

int rate[25] = { 0 };
double daymoney;
double calcMoney(DateM t1, DateM t2) {
	double sum = 0;
	while (!(t1==t2))
	{
	
		sum += rate[t1.h] * 0.01;
		++t1;
	}
	return sum;
}


map<string,vector<node> > A;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	daymoney = 0;
	for (int i = 0; i < 24; i++) {
		scanf("%d",&rate[i]);
		daymoney += rate[i] * 0.01 * 60;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		char ts[1010];
	
		char ts2[1010];
		scanf("%s %d:%d:%d:%d %s",ts,&t.d.M, &t.d.day, &t.d.h, &t.d.m,ts2);
		t.name = ts;
		if (ts2[1] == 'n') {
			t.state = 0;
		}
		if (ts2[1] == 'f') {
			t.state = 1;
		}
		A[t.name].push_back(t);
	}

	

	for (map<string, vector<node> >::iterator it = A.begin(); it != A.end(); it++) {
		sort((*it).second.begin(),(*it).second.end());
	}
	for (map<string, vector<node> >::iterator it = A.begin(); it != A.end(); it++) {
	
		vector< pair<node, node> > tv;
		double totalsum = 0;
		for (int i = 0; i < A[(*it).first].size() - 1; i++) {
			if (A[(*it).first][i].state == 0 && A[(*it).first][i + 1].state == 1) {
				tv.push_back(make_pair(A[(*it).first][i], A[(*it).first][i + 1]));
				i++;
			}
		}

			if (tv.size()>0) {
				
				printf("%s %02d\n",tv[0].first.name.c_str(),tv[0].first.d.M);
				for (int i = 0; i < tv.size(); i++) {
					double sum = 0;
					sum = calcMoney(tv[i].first.d, tv[i].second.d);
					totalsum += sum;
					printf("%02d:%02d:%02d %02d:%02d:%02d",
						tv[i].first.d.day, tv[i].first.d.h, tv[i].first.d.m,
						tv[i].second.d.day, tv[i].second.d.h, tv[i].second.d.m
					);

					int diff = tv[i].second.d - tv[i].first.d;
					printf(" %d $%.2f\n",diff,sum);
				}
				printf("Total amount: $%.2f\n", totalsum);
			}
		
		
	}
	

	//printf();

	return 0;
}
