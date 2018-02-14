
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
#include <functional>
#include <sstream>
using namespace std;
class node {
public:
	string str;
	vector<string> v;
	bool operator<(const node&t) {
		return this->str < t.str;
	}
};
vector<string> split(string s) {
	vector<string> v;
	istringstream f(s);
	string t;
	while (getline(f, t, ' ')) {
		v.push_back(t);
	}
	
	return v;
}

vector<node>A;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m;
	
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		node t;
		getline(cin, t.str);
		string str;
		for (int j = 0; j < 2; j++) {
			getline(cin, str);
			t.v.push_back(str);
		}
		getline(cin, str);
		vector<string>tt= split(str);
		for (int j = 0; j < tt.size(); j++)
			t.v.push_back(tt[j]);

		for (int j = 0; j < 2; j++) {
			getline(cin, str);
			t.v.push_back(str);
		}
		A.push_back(t);

	}

	sort(A.begin(), A.end());
	cin >> m;
	getchar();
	char *tmpstr = new char[1010];
	for (int i = 0; i < m; i++) {
		
		;
		//getline(cin, tmpstr, '\n');
		fgets(tmpstr,1010,stdin);
		if (tmpstr[strlen(tmpstr) - 1] == '\n')tmpstr[strlen(tmpstr) - 1] = '\0';
		cout << tmpstr<<endl;
		
		while ((*tmpstr) != ':')tmpstr++;
		tmpstr+=2;
		string tttmpstr = tmpstr;
		bool flag = false; 
		for(int u = 0;u<A.size();u++)
			for (int v = 0; v < A[u].v.size(); v++) {
				if (tttmpstr == A[u].v[v]) {
					cout << A[u].str << endl;
					flag = true;
					break;
				}
			}

		if (!flag) {
			cout << "Not Found" << endl;
		}
		
	}
	//printf();

	return 0;
}