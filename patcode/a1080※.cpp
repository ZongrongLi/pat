
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
#include <stack>
using namespace std;

class node {
public:
	int id;
	int ge;
	int gi;
	int rank;
	int choice[8];
	node() {
		id = 0;
		rank = 0;
		ge = 0;
		gi = 0;
		memset(choice, 0, sizeof(choice));
	}
	bool operator<(const node&t) {
		int a = this->ge + this->gi;
		int b = t.ge + t.gi;
		if ( a!=b )return a>b;
		else if (this->ge != t.ge)return this->ge > t.ge;
		else return false;
	}
};
int quota[100] = {0};
vector<node> A[100];
vector<node> tot;
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0,m,k;
	scanf("%d %d %d", &n,&m,&k);
	for (int i = 0; i < m; i++) {
		scanf("%d",&quota[i]);
	}
	
	for (int i = 0; i < n; i++) {
		node t;
	
		scanf("%d %d",&t.ge,&t.gi);
		for (int j = 0; j < k; j++)
			scanf("%d",&t.choice[j]);
		t.id = i;
		tot.push_back(t);
	}
	sort(tot.begin(),tot.end());
	
	tot[0].rank = 1;
	for (int i = 1; i < tot.size(); i++) {
		if (tot[i].ge == tot[i - 1].ge && tot[i].gi == tot[i - 1].gi)tot[i].rank = tot[i - 1].rank;
		else
		{
			tot[i].rank = i + 1;
		}
	}

	
			
			for (vector<node>::iterator it = tot.begin() ; it != tot.end(); it++) {
				for (int i = 0; i < k; i++) {
					int school = it->choice[i];

					if (quota[school] > 0) {
						quota[school]--;
						A[school].push_back(*it);
						break;;

					}
					else if (A[school].size() != 0 && A[school].back().rank == it->rank) {
						quota[school]--;
						A[school].push_back(*it);
						break;
					}
				}
			}
		
	
			for (int i = 0; i < m; i++) {
				if (A[i].size() == 0)printf("\n");
				vector<int>t;
				for (int j = 0; j < A[i].size(); j++)
					t.push_back(A[i][j].id);
				sort(t.begin(), t.end());
				for (int j = 0; j < t.size(); j++) {
					if(j!=t.size()-1)
					printf("%d ", t[j]);
					else
						printf("%d\n", t[j]);
				}
			}
	return 0;
}
