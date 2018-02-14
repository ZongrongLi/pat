
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
class node{
public:
	int art;
	int plt;
	int tag;
	int id;
	int st;
};

queue<node>q;
int table[200] = {0};
int vtable[200] = { 0 };
int early = 8 * 3600;
int late = 21 * 3600;
int tablecnt[200] = { 0 };
vector<node>ans;
int n = 0,k,m;
vector<node>people;
int pp = 0;
bool cmp1(node a,node b) {
	return a.art < b.art;
}
bool cmp2(node a, node b) {
	return a.st < b.st;
}

int getvipT() {
	for (int i = 1; i <= k; i++) {
		if (table[i] <= 0 && vtable[i] == 1)return i;
	}
	return -1;
}
node getvipP() {
	int t = q.size();
	node A;
	A.art = -1;
	bool flag = true;
	while (t--)
	{
		node c = q.front();
		q.pop();
		if (c.tag == 1 && flag) {
			A = c;
			flag = false;
			continue;
		}
		q.push(c);
	}
	return A;
}
int getempty() {
	for (int i = 1; i <= k; i++) {
		if (table[i] <= 0 )return i;
	}
	return -1;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		scanf("%d:%d:%d %d %d",&a,&b,&c,&d,&e);
		node t;
		if (e == 1)t.tag = 1;
		else t.tag = 0;
		t.art = a * 3600 + b * 60 + c;
		if (d > 120)d = 120;
		t.plt = d * 60;
		people.push_back(t);
	}
	sort(people.begin(), people.end(), cmp1);
	scanf("%d %d", &k, &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d",&t);
		vtable[t] = 1;
	}
	for (int s = early; s < late; s++) {
	
		for (int i = 1; i <= k; i++) 
			table[i]--;
		
		while (pp<n&&s>=people[pp].art)
			q.push(people[pp++]);
		
		
		if (getvipT() != -1 ) {
			node t = getvipP();
			
			if (t.art != -1) {
				t.st = s;
				
				ans.push_back(t);
				int tmp = getvipT();
				tablecnt[tmp]++;
				table[tmp] = t.plt;
				
				continue;
			}
		}
		if(getempty()!=-1&&!q.empty())
		{
			
			int tmp = getempty();
			node c = q.front();
			q.pop();
			table[tmp] = c.plt;
			tablecnt[tmp]++;
			c.st = s;
			ans.push_back(c);
		}
	}
	sort(ans.begin(), ans.end(), cmp2);
	for (int i = 0; i < ans.size(); i++) {
		node t = ans[i];
		if(t.st<late)
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",t.art/3600,t.art/60%60,t.art%60,
			t.st / 3600, t.st / 60 % 60, t.st % 60,(int)round(1.0*(t.st-t.art)/60) );
	}
	for (int i = 1; i <= k; i++) {
		if(i!=k)
			printf("%d ",tablecnt[i]);
		else 
			printf("%d",tablecnt[i]);
	}
	return 0;
}
