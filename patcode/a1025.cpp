#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
class student{
public:
	char num[15];
	int score;
	int trank;
	int lrank;
	int gang;
	bool operator < (student &T) {
		if (this->score != T.score)
			return this->score > T.score;
		else
			return strcmp(this->num,T.num) < 0;
	}
};
student data[100][300];
student total[30000];
int main() {
	freopen("./test.txt", "r", stdin);
	int N,n,totalcnt=0;
	int tp = 0;
	scanf("%d",&N);
	int gangcnt = 1;
	for(int i=0;i<N;i++) {
		scanf("%d", &n);
		totalcnt += n;
		for(int j=0;j<n;j++)
		{
			scanf("%s %d",&data[i][j].num, &data[i][j].score);
			
			data[i][j].gang = gangcnt;
		}
		std::sort(data[i], data[i] + n);
		data[i][0].lrank = 1;
		total[tp++] = data[i][0];
		for (int j = 1; j < n; j++) {
			if (data[i][j].score == data[i][j - 1].score)
				data[i][j].lrank = data[i][j - 1].lrank;
			else 
				data[i][j].lrank = j+1;

			total[tp++] = data[i][j];
		}
		gangcnt++;
	}

	std::sort(total, total + totalcnt);
	total[0].trank = 1;
	for (int i = 1; i < totalcnt; i++) {
		if (total[i].score == total[i-1].score)
			total[i].trank = total[i-1].trank;
		else
			total[i].trank = i+1;
	}
	printf("%d\n",totalcnt);
	for (int i = 0; i < totalcnt; i++) {
		printf("%s %d %d %d\n",total[i].num,total[i].trank, total[i].gang, total[i].lrank);
	}
	//scanf("%d %d %d", &a, &b, &d);

	return 0;
}