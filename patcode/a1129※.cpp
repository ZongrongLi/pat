
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
int n = 0,k;
int H[50200] = { 0 };

class node {
public:
	int id;
	int  ti;
	node() {
		id = ti = 0;
	}
	bool operator<(const node&t)const {
		if (this->ti != t.ti)return this->ti > t.ti;
		return this->id < t.id;
	}

};
set<node> s;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);

		if (i != 0) {
			printf("%d:",t);
			set<node>::iterator it;
			int cnt = 0;
			for (it = s.begin(); it != s.end() && cnt < k; it++) {
				printf(" %d", it->id);
				cnt++;
			}
			printf("\n");
		}
	
		node tmp;
		tmp.id = t;
		tmp.ti = H[t];
		H[t]++;
		if (s.find(tmp) != s.end()) {
			s.erase(s.find(tmp));
		}
		tmp.ti += 1;
		s.insert(tmp);
	}
	//printf();

	return 0;
}
