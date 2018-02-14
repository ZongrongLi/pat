
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
	string id;
	int grade;
	node(){
		grade = 0;
	}
};

vector<node> A[1000010];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ts[100];
		char ts1[100];
		node t;
		scanf("%s %s %d",ts,ts1,&t.grade);
		t.name = ts;
		t.id = ts1;
		A[t.grade].push_back(t);
	}
	int g1, g2;
	scanf("%d %d",&g1,&g2);
	bool flag = false;
	for (int i = g2; i >= g1; i--) {
		if (A[i].size() != 0) {
			printf("%s %s\n", A[i][0].name.c_str(), A[i][0].id.c_str());
			flag= true;
		}
	}
	if (!flag)
		printf("NONE\n");
	//printf();

	return 0;
}
