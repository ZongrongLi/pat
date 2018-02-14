
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
int n = 0;
class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};
int pre[50010];
int ino[50010];
node *root = NULL;

bool flag = false;

void create(node *&t,int pl,int pr,int il,int ir) {
	if (flag)return;
	if (pl > pr || il > ir)return;
	t = new node;
	t->d = pre[pl];
	
	if (pl == pr || il == ir) {
		flag = true;
		printf("%d",t->d);
		return;
	}
	int idx;
	for (int i = il; i <=ir; i++)if (t->d == ino[i]) {
		idx = i;
		break;
	}
	int len1 = idx - il;
	int len2 = il - idx;
	create(t->l,pl+1,pl+len1,il,idx-1);
	create(t->r, pl+len1+1, pr, idx+1, ir);
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d",&pre[i]);
	for (int i = 0; i < n; i++) 
		scanf("%d", &ino[i]);
	
	create(root, 0, n - 1,0,n-1);
	
	return 0;
}