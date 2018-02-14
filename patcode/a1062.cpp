
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
	int v;
	int t;
	
	node() {
		v = 0;
		t = 0;
	}
	bool operator <(const node &t) {
		if (this->v + this->t != t.v + t.t)
			return this->v + this->t > t.v + t.t;
		else if (this->v != t.v)
			return this->v > t.v;
		else
			return this->id < t.id;
	}
};
vector<node>sage;
vector<node>nobel;
vector<node>fool;
vector<node>shabi;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	int l, h;
	scanf("%d %d %d", &n,&l,&h);
	for (int i = 0; i < n; i++) {
		node t;
		char a[20];
		scanf("%s %d %d",a,&t.v,&t.t);
		//cin >> t.id >> t.v >> t.t;
		t.id = a;
		if (t.v < l||t.t<l)continue;
		else if (t.v >= h && t.t >=h )sage.push_back(t);
		else if (t.v >= h && t.t < h)nobel.push_back(t);
		else if (t.v < h&&t.t < h) {
			if (t.v >= t.t)
				fool.push_back(t);
			else
				shabi.push_back(t);
		}
		else
			shabi.push_back(t);
	}

	sort(sage.begin(),sage.end());
	sort(nobel.begin(), nobel.end());
	sort(fool.begin(), fool.end());
	sort(shabi.begin(), shabi.end());
	cout << sage.size() + nobel.size() + fool.size() + shabi.size() << endl;
	for (int i = 0; i < sage.size(); i++) {
		//cout << sage[i].id <<" "<< sage[i].v<<" " << sage[i].t<<endl;
		printf("%s %d %d\n",sage[i].id.c_str(),sage[i].v,sage[i].t);
	}
	for (int i = 0; i < nobel.size(); i++) {
		//cout << nobel[i].id<<" " << nobel[i].v<<" " << nobel[i].t<<endl;
		printf("%s %d %d\n", nobel[i].id.c_str(), nobel[i].v, nobel[i].t);

	}
	for (int i = 0; i < fool.size(); i++) {
		//cout << fool[i].id<<" " << fool[i].v<<" " << fool[i].t<<endl;
		printf("%s %d %d\n", fool[i].id.c_str(), fool[i].v, fool[i].t);
	}
	for (int i = 0; i < shabi.size(); i++) {
		//cout << shabi[i].id << " " << shabi[i].v << " " << shabi[i].t << endl;
		printf("%s %d %d\n", shabi[i].id.c_str(), shabi[i].v, shabi[i].t);
	}
	//printf();


	return 0;
}
