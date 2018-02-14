// patcode.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include<functional>
#include <iostream>
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
int n = 0, m, k, Q;


class node {
public:
	int id;
	int time;
	int etime;
	bool operator<(node &t) {
		return this->id < t.id;
	}
	node() {
		etime = 0x3fffffff;
	}
};
node A[2000];
vector<node>B;
vector< queue<node> > q;
int EARLY = 8 * 60;
int LATE = 17 * 60;
int getempty() {
	int Minl = 65535;
	int Mini = 0;
	for (int i = 0; i<n; i++)
		if (q[i].size() < m) {
			if (Minl>q[i].size()) {
				Minl = q[i].size();
				Mini = i;
			}
		}
	if (Minl == 65535)
		return -1;
	return Mini;

}


int main() {
	freopen("./test.txt", "r", stdin);
	int cnt = 0;

	scanf("%d %d %d %d", &n, &m, &k, &Q);
	q.resize(n + 1);
	int idx = 1;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &A[i].time); A[i].id = i;
	}
	for (int s = EARLY; s <= LATE; s++) {
		for (int i = 0; i<n; i++) {
			while (!q[i].empty() && s >= q[i].front().etime) {
				B.push_back(q[i].front());
				q[i].pop();
			}
		}

		while (getempty() != -1&&idx<=k&&s<LATE) {
			int id = getempty();
			if(q[id].size()==0)
				A[idx].etime = s + A[idx].time;
			else 
				A[idx].etime = A[idx].time + q[id].back().etime;
			//cout << "--" << s << endl;
			q[id].push(A[idx++]);
		}
	}
	for (int i = 0; i<n; i++) {
		while (!q[i].empty() ) {
			B.push_back(q[i].front());
			q[i].pop();
		}
	}
	for (int i = 0; i<Q; i++) {
		int t;
		scanf("%d", &t);
		bool flag = false;
		for (int j = 0; j < B.size(); j++) {
			//cout << "--" << B[j].etime - B[j].time << endl;
			if (B[j].id == t&&B[j].etime-B[j].time<LATE) {
				printf("%02d:%02d\n", B[j].etime / 60, B[j].etime % 60);
				flag = true;
				break;
			}
			
		}
		if (!flag)printf("Sorry\n");
		
	}
	return 0;
}
