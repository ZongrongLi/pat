
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include<iostream>
#include <string>;
using namespace std;

class node {
public:
	int id;
	string str;
};
vector<node>A;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m=0;
	scanf("%d", &n);
	A.resize(1010);
	for (int i = 0; i < n; i++) {
		node t;
		int c;
		cin >> t.str >> c >> t.id;
		A[c] = t;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d",&t);
		cout << A[t].str << " " << A[t].id << endl;
	}

	//printf();

	return 0;
}
