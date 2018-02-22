
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
#include <set>
using namespace std;
int n = 0,m;
class problem {
public:
	int id;
	int g;
	int tot;
	int sel;
	int ans;

};
int P[200] = { 0 };
vector<problem>vt;
vector<int>ans;
int Maxw=-1;
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d", &n,&m);
	problem tmp;
	vt.push_back(tmp);
	for (int i = 1; i <= m; i++) {
		problem t;
		int c;
		t.id = i;
		scanf("%d %d %d ",&t.g,&t.tot,&c);
		int sum = 0;
		t.sel = c;
		for (int j = 0; j < c; j++) {
			char tmp;
			scanf("%c",&tmp);
			getchar();
			sum = sum * 26 + tmp;
		}
		t.ans = sum;	
		vt.push_back(t);
	}
	//printf();
	
	for (int i = 1; i <= n; i++) {
		char str[3000];
		cin.getline(str, 3000);
		int len = strlen(str);
		int idx = 1;
		int sum = 0;
		int score = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] == '(' || str[j] == ' ' || isdigit(str[j]))continue;
			if (str[j] == ')') {
				if (vt[idx].ans == sum) {
					//dv
					score += vt[idx].g;
				}
				else {
					//cuo
					P[idx]++;
					if (Maxw < P[idx]) {
						Maxw = P[idx];
						ans.clear();
						ans.push_back(idx);
					}
					else if (Maxw == P[idx])
						ans.push_back(idx);
				}
				sum = 0;
				idx++;
			}
			if (isalpha(str[j])) {
				sum = sum * 26 + str[j];
			}
		}
		printf("%d\n",score);
	
		//getchar();
	}
	if (Maxw==-1) {
		printf("Too simple");
	}
	else {
		printf("%d ",Maxw);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			if(i!=ans.size()-1)
				printf("%d ",ans[i]);
			else 
				printf("%d",ans[i]);
		}
	}
	return 0;
}