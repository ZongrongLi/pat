
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

int n,p,k;
int factor[20000];
int maxi = 0;
void init(){
	maxi = 1;
	int t = 0;
	factor[0] = 0;
	while (factor[maxi-1]<=n)
	{
		t = 1;
		for (int i = 0; i < p; i++)
			t *= maxi;
		factor[maxi] = t;
		maxi++;
	}
	maxi--;
}
vector<int> maxsecq ;
int maxsum = 0;
bool flag = false;
vector<int>tmp;
void dfs(int idx,int data,int d,int sum) {
	if (idx < 1)return;
	if (data < 0)return ;
	if (d > k)return;//--------------------
	if (d == k&&data == 0) {
		//sum += idx;
		
		
		flag = true;
		if (maxsum < sum) {
			maxsum = sum;
			maxsecq = tmp;
		}
		return;
	}
	tmp.push_back(idx);
	dfs(idx, data - factor[idx], d + 1, sum + idx);
	tmp.pop_back(); 
	dfs(idx - 1, data, d, sum);
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d", &n,&k,&p);
	init();
	dfs(maxi-1,n,0,0);
	
	if (!flag) {
		printf("Impossible\n");
		return 0;
	}
	printf("%d =", n);
	for (int i = 0; i < maxsecq.size(); i++) {
		printf(" %d^%d",maxsecq[i],p);
		if (i != maxsecq.size() - 1)
			printf(" +");
	}
	return 0;
}