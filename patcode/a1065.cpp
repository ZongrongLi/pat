
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <string>
using namespace std;


#define  LL long long
int main() {
	freopen("./test.txt", "r", stdin);
	
	int n = 0;
	
	
	LL a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld",&a,&b,&c);
		LL t = a + b;
		bool flag = false;
		if (a > 0 && b > 0 && t < 0)flag = true;
		else if (a < 0 && b < 0 && t>=0)flag = false;//还真是 这块
		else
		{
			if (t > c)flag = true;
			else
				flag = false;

		}
		if(flag)
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n", i + 1);
	}
	//printf();

	return 0;
}
