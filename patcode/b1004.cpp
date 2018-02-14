
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
	string id;
	string name;
	int score;
	node() {
		score = 0;
	}
	bool operator < (const node&T) {
		return this->score < T.score;

	}
};


vector<node>A;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node t;
		cin >> t.name >> t.id >> t.score;
		A.push_back(t);
	}

	sort(A.begin(), A.end());
	
	cout << A[A.size() - 1].name << " " << A[A.size()-1].id << endl;
	cout << A[0].name << " " << A[0].id << endl;
	//printf();

	return 0;
}