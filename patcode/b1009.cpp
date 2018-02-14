
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
#include <sstream>
using namespace std;

vector<string>a;
int main() {
	freopen("./test.txt", "r", stdin);
	string s;
	char ssss[1010];
	fgets(ssss, 1010, stdin);
	if (ssss[strlen(ssss) - 1] == '\n')ssss[strlen(ssss) - 1] = '\0';
	s = ssss;
	istringstream f(s);
	string s1;
	while (getline(f, s1, ' ')) {
	a.push_back(s1);
	}
	//printf();
	for (int i = a.size() - 1; i >= 0; i--)
		if (i != 0) {
			cout << a[i] << " ";
		}
		else
			cout << a[i];
	return 0;
}