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
	string name;
	int age;
	int trea;
	node() {
		age = 0;
		trea = 0;
	}

	bool operator <(const node &t) {
		if(this->trea != t.trea)
		return this->trea > t.trea;
		if(this->age != t.age)
		return this->age < t.age;
		return this->name < t.name;
	}
};
vector<node> total;
vector<node> total1;
int A[208] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,k=0;
	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		char ts[20];
		node t;
		scanf("%s %d %d",ts,&t.age,&t.trea);
		t.name = ts;
		total.push_back(t);
	}

	sort(total.begin(), total.end());
	for (int i = 0; i < total.size(); i++) {
		if (A[total[i].age] <= 100) {
			A[total[i].age]++;
			total1.push_back(total[i]);
		}
	}
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n",i+1);
		int cnt = 0;
		for (int j = 0; j < total1.size(); j++) {
			if (total1[j].age<amin || total1[j].age >amax)continue;
			cnt++;
			if (cnt == m+1)break;
			printf("%s %d %d\n", total1[j].name.c_str(), total1[j].age, total1[j].trea);
		}

		if (cnt == 0)
			printf("None\n");

	}
	//printf();

	return 0;
}
