
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

vector<string>vid;
vector<string>vpass;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	bool flag = false;
	int tcnt = 0;
	for (int i = 0; i < n; i++) {
		string s1,s2;
		cin >> s1 >> s2;
	
		int cnt = 0;
		for (int j = 0; j < s2.size(); j++) {
			if (s2[j] == '0')s2[j] = '%';
			else if (s2[j] == '1')s2[j] = '@';
			else if (s2[j] == 'l')s2[j] = 'L';
			else if (s2[j] == 'O')s2[j] = 'o';
			else
				cnt++;
		}
		if (cnt < s2.size()) {
			//cout << s1 << " " << s2<<endl;
			vid.push_back(s1);
			vpass.push_back(s2);
			tcnt++;
			flag = true;
		}
	}
	if (!flag) {
		cout << "There ";
		if (n == 1)cout << "is ";
		else cout << "are ";

		if (n == 1)
			cout << n << " account and no account is modified";
		else
			cout << n << " accounts and no account is modified";
	}
	else {
		cout << tcnt << endl;
		for (int i = 0; i < vid.size(); i++)
			cout << vid[i] << " "<<vpass[i]<<endl;
	}
	//printf();

	return 0;
}
