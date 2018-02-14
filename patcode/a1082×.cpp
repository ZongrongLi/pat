
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
string digit[10] = {
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};
vector<string> tran4(int k) {
	string s;
	vector<string>tt;
	int a[4];
	a[0] = k / 1000;
	a[1] = k / 100 % 10;
	a[2] = k / 10 % 10;
	a[3] = k % 10;
	if (a[0] == 0 && a[1] == 0 && a[2] == 0 & a[3] == 0) {
		tt.push_back("ling");
		return tt;
	}
	int cnt = 0;
	
	if (a[0] != 0) {
		tt.push_back(digit[a[0]]);
		tt.push_back("Qian");
	}
	else
		tt.push_back("ling");

	if (a[1] != 0) {
		tt.push_back(digit[a[1]]);
		tt.push_back("Bai");
	}
	else {
		tt.push_back("ling");
	}

	if (a[2] != 0) {
		tt.push_back(digit[a[2]]);
		tt.push_back("Shi");
	}
	else
		tt.push_back("ling");

	if(a[3]!=0)
		tt.push_back(digit[a[3]]);
	
	while (tt[0]=="ling")
	{
		tt.erase(tt.begin());
	//	tt.erase(tt.begin());
	}
	cnt = 0;
	vector<string>::iterator bf, af;
	for (vector<string>::iterator it =tt.begin(); it != tt.end(); it++) {
		if (it!=tt.begin()&& (*it) == (*(it - 1))) {
			if ((*it) == "ling")
				it = tt.erase(it);
			it--;
		}
	}
	
	return  tt;
}

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	cin >> n;
	bool flag = false;
	string ans;
	vector<string>sv;
	if (n < 0) {
		flag = true;
		sv.push_back("Fu");
		n *= -1;
	}
	int Y = n / 100000000;
	int a = n / 10000 % 10000;
	int b = n % 10000;
	//vector<string>ss = tran4(n);
	if (Y != 0) {
		sv.push_back(digit[Y]);
		sv.push_back("Yi");
	}
	vector<string>t1 = tran4(a);
	vector<string>t2 = tran4(b);
	if (Y != 0 && t1[1] != "Qian")
		sv.push_back("ling");
		for (int i = 0; i < t1.size(); i++)
			sv.push_back(t1[i]);
		if (a != 0) {
			sv.push_back("Wan");
			if (t2[1] != "Qian")
				sv.push_back("ling");
		}
	for (int i = 0; i < t2.size(); i++)
		sv.push_back(t2[i]);

	
	for (vector<string>::iterator it = sv.begin(); it != sv.end(); it++)
		if (it!=sv.begin()) {
			if ((*it) == "ling")
				if ((*it) == (*(it-1)))sv.erase(it-1);
		}
	vector<string>::iterator it = sv.begin();
	it++;
	for (; it != sv.end(); it++)
		if ((*it) == "ling")
		{
			it =sv.erase(it);
			it--;
		}
		else
			break;

	for (vector<string>::iterator it = sv.begin(); it != sv.end(); it++) {
		cout << (*it);
		if ((it+1)!=sv.end()) {
			cout << " ";
		}
	}
	//char str[1010];
	//sprintf(str,"%d");
	return 0;
}
