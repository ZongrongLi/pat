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
int A[62][1282][200];
int n = 0,m,l,T;
int sum = 0;
class node {
public:
	int a;
	int b;
	int c;
	node(int i,int j,int k){
		a = i;
		b = j;
		c = k;
	}
	node() {
		a = 0;
		b = 0;
		c = 0;
	}
};
queue<node> q;
void bfs() {
	for(int k=0;k<l;k++)
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (A[k][i][j] != 1)continue;
				
				A[k][i][j] = -1;
				q.push(node(k,i,j));
				int sumt = 0;
				//cout << k << " " << i << " " << j<<endl;
				while (!q.empty())
				{
					node t =q.front();	
					q.pop();			
					sumt++;
					if(t.b-1>=0)
						if (A[t.a][t.b - 1][t.c] == 1) {
							q.push(node(t.a, t.b - 1, t.c));
							A[t.a][t.b-1][t.c] = -1;
						}
					if(t.b+1<n)
						if ( A[t.a][t.b + 1][t.c] == 1) {
							q.push(node(t.a, t.b + 1, t.c));
							A[t.a][t.b+1][t.c] = -1;
						}
					if(t.c>=1)
						if (A[t.a][t.b][t.c - 1] == 1) {
							q.push(node(t.a, t.b, t.c - 1));
							A[t.a][t.b][t.c - 1] = -1;

						}
					if(t.c+1<m)
						if (A[t.a][t.b][t.c + 1] == 1) {
							q.push(node(t.a, t.b, t.c + 1));
							A[t.a][t.b][t.c + 1] = -1;
						}
					if(t.a+1<l)
						if (A[t.a + 1][t.b][t.c] == 1) {
							q.push(node(t.a + 1, t.b, t.c));
							A[t.a+1][t.b][t.c] = -1;
						}
					if(t.a>=1)
						if (A[t.a - 1][t.b][t.c] == 1) {
							q.push(node(t.a - 1, t.b, t.c));
							A[t.a - 1][t.b][t.c] = -1;
						}
				}
				//cout << sumt << endl;
				if(sumt>=T)
					sum += sumt;
			}
			
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, 0, sizeof(A));
	//memset(v, 0, sizeof(v));
	scanf("%d %d %d %d", &n,&m,&l,&T);
	for (int k = 0; k<l; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d",&A[k][i][j]);
			}
	bfs();
	printf("%d",sum);
	//printf();

	return 0;
}
