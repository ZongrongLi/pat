
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

int A[20] = {0};
int main() {
	freopen("./test.txt", "r", stdin);
	char ss[1010];
	fgets(ss,1010,stdin);
	for (int i = 0; i < strlen(ss); i++)
		A[ss[i] - '0']++;

	for (int i = 0; i < 10; i++) {
		if (A[i] == 0)continue;
		cout << i << ":" << A[i]<<endl;
	}
	//printf();

	return 0;
}