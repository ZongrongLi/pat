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

vector<string>A;
bool cmp(string s1, string s2) {
	string st1 = s1 + s2;
	string st2 = s2 + s1;
	return st1 < st2;
}
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[20];
		scanf("%s",s);
		A.push_back(s);

	}
	sort(A.begin(), A.end(), cmp);
	int c = 0;
	int idx = 0;
	while (idx<A.size()&&atoi(A[idx++].c_str()) == 0);
	idx--;
	if (idx == A.size() - 1) {
		printf("0");
		return 0;
	}
	while (A[idx][c++] == '0');
	c--;
	while (A[idx][c] != '\0')printf("%c",A[idx][c++]);
	for (int i = idx+1; i < A.size(); i++)
		printf("%s",A[i].c_str());

	return 0;
}
