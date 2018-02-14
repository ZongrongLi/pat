
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
int n = 0,k;
class node {
public:
	int d;
	int ad;
	int ne;
};
node A[100000];
vector<node>ans;
int main() {
	freopen("./test.txt", "r", stdin);
	int root;
	scanf("%d %d %d",&root, &n,&k);
	
	for (int i = 0; i < n; i++) {
		node t;
		scanf("%d %d %d",&t.ad,&t.d,&t.ne);
		A[t.ad] = t;
	}
	int t = root;
	while (t!=-1)
	{
		if (A[t].d < 0)ans.push_back(A[t]);
		t = A[t].ne;
	}
	t = root;
	while (t != -1)
	{
		if (A[t].d >=0&&A[t].d<=k)ans.push_back(A[t]);
		t = A[t].ne;
	}
	t = root;
	while (t != -1)
	{
		if (A[t].d >k)ans.push_back(A[t]);
		t = A[t].ne;
	}
	for (int i = 0; i < ans.size()-1; i++) {
		if(i!=n-1)
		printf("%05d %d %05d\n",ans[i].ad,ans[i].d,ans[i+1].ad);
	}
	printf("%05d %d -1\n",ans[ans.size()-1].ad,ans[ans.size()-1].d);
	//printf();

	return 0;
}