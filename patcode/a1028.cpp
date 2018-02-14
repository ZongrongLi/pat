
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
	int grade;
	node(){
		grade = 0;
	}
};

bool cmp1(node &a, node &b) {
	return a.id < b.id;

}
bool cmp2(node &a, node &b) {
	if(a.name!=b.name)
	return a.name < b.name;
	else 
		return a.id < b.id;
}
bool cmp3(node &a, node &b) {
	if(a.grade !=b.grade)
	return a.grade < b.grade;
	else
		return a.id < b.id;
}

vector<node >A;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,c=0;
	scanf("%d %d", &n,&c);
	for (int i = 0; i < n; i++) {
		node t;
		char ts[1010];
		char ts1[1010];
		scanf("%s %s %d",ts,ts1,&t.grade);
		t.id = ts;
		t.name = ts1;
		A.push_back(t);
	}

	if (c == 1)sort(A.begin(),A.end(),cmp1);
	if (c == 2)sort(A.begin(), A.end(), cmp2);
	if (c == 3)sort(A.begin(), A.end(), cmp3);

	for (int i = 0; i < A.size(); i++)
		//cout << A[i].id << " " << A[i].name <<" "<< A[i].grade << endl;
		printf("%s %s %d\n", A[i].id.c_str(), A[i].name.c_str(), A[i].grade);
	//printf();

	return 0;
}
