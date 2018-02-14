
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
int n = 0;
int A1[800];
int B[800];
int A2[800];
bool cmp(int a[], int b[]){
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
bool insert(int a[],int k) {
	int tmp = a[k];
	int i = k - 1;
	while (i>-1&& tmp<a[i])
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i+1] = tmp;
	if (i + 1 == k)return false;
	else return true;
}
bool isdone(int a[]) {
	for (int i = 1; i < n; i++)
		if (a[i - 1] > a[i])return false;
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A1[i]);
		A2[i] = A1[i];
		
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		
	}
	//printf();
	bool flag = false;
	for (int i = 1; i < n; i++) {
		insert(A1, i);
		if (cmp(A1, B)) {
			flag = true;
			cout << "Insertion Sort"<<endl;
			 if(!isdone(A1))
				insert(A1,i + 1);
			for (int j = 0; j < n; j++)
				if (j != n - 1)cout << A1[j] << " ";
				else cout << A1[j];
			break;
		}
	}
	if (n == 1) {
		cout << "Insertion Sort" << endl;
		printf("%d",A1[0]);
		return 0;
	}
	if (flag)return 0;
	cout << "Merge Sort"<<endl;
	int cnt = 1;
	int maxcnt = 0;
	

	int i = 0;
	int maxc = 2;
	bool flag1 = false;
	while (true)
	{
		i = 0;
		while (i < n)
		{
			int t = min(n, i +  maxc);
			sort(A2 + i, A2  + t);
			i += maxc;
		}
		if (flag1)break;
		if (cmp(A2, B)) {
			flag1 = true;
		}
		if (maxc >= n)break;
		maxc *= 2;
	}

	for (int j = 0; j < n; j++)
		if (j != n - 1)cout << A2[j] << " ";
		else cout << A2[j];
	
	
	return 0;
}


