
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
	char gender;
	string id;
	int grade;
	node() {
		grade = -1;
	}
	bool operator < (const node&t) {
		return this->grade < t.grade;
	}
};
node maxnF,minM;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	minM.grade = 65535;
	for (int i = 0; i < n; i++) {
		node t;
		cin >> t.name >> t.gender >> t.id >> t.grade;
		if (t.gender == 'F') {
			if (maxnF < t)maxnF = t;
		}
		else
		{
			//minM = minM < t ? minM : t;
			if (t<minM )minM = t;
		}
	}
	if (maxnF.grade != -1)
		cout << maxnF.name << " " << maxnF.id<<endl ;
	else
		printf("Absent\n");


	if (minM.grade != 65535)
		cout << minM.name << " " << minM.id << endl;
	else
		printf("Absent\n");

	if (maxnF.grade == -1 || minM.grade == 65535)
		cout << "NA";
	else {
		cout << maxnF.grade - minM.grade;
	}
	return 0;
}