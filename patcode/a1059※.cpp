
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LL long long
bool isprim(LL num) {
	if (num == 1)return false;
	LL k = (LL)sqrt(1.0 * num);
	for (LL i = 2; i <= k; i++)
		if (num%i == 0)return false;
	return true;
}

const int maxn = 100010;
LL primtable[maxn];
LL cnt = 0;
void createprimtable() {
	for (LL i = 2; i < maxn; i++)
		if (isprim(i))primtable[cnt++] = i;
}

class factor {
public:
	int cnt;
	int data;
};
factor s[maxn];
LL top=0;
int main() {
	freopen("./test.txt", "r", stdin);
	createprimtable();
	long long n = 0;
	scanf("%ld", &n);
	if (n == 1) {
		printf("1=1"); return 0;
	}
	LL rn = n;
	long long k = (long long)sqrt(1.0*n);
	/*for (int i = 0; i <= k; i++) {
		if(n % )
	}*/
	int facnt = 0;
	top = -1;
	while ( primtable[facnt]<=k) {
		if (n%primtable[facnt] == 0) {
			factor tt;
			tt.data = primtable[facnt];
			tt.cnt = 1;
			n = n / primtable[facnt];
			while (n%primtable[facnt]==0)
			{
				n = n / primtable[facnt];
				tt.cnt ++;
			}
			s[++top] = tt;
		}
		facnt++;
	}
	if (n != 1) {
		factor tt1;
		tt1.data = n;
		tt1.cnt = 1;
		s[++top] = tt1;
	}
	printf("%ld=",rn);
	for (int i = 0; i <= top; i++) {
		printf("%d", s[i].data);
		if (s[i].cnt > 1) {
			printf("^%d", s[i].cnt);
		}
		if (i != top)printf("*");
	}
	//printf();

	return 0;
}