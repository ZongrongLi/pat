
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdlib>




bool cmp(char a, char b) {
	return a < b;
}
void todescend(char *s) {
	int len = strlen(s);
	std::sort(s,s+len,  cmp);
}

void toascend(char *s) {
	int len = strlen(s);
	std::sort(s, s + len);
}
int main() {
	freopen("./test.txt", "r", stdin);
	int d;
	char str[8];
	scanf("%d",&d);
	int len = strlen(str);
	sprintf(str, "%04d", d);


	char cs1[10], cs2[10];
	while (1) {
		strcpy(cs1, str);
		strcpy(cs2, str);
		toascend(cs1);
		todescend(cs2);
		int a = atoi(cs2);
		int b = atoi(cs1);
		int c = a - b;
		printf("%s - %s = %04d\n", cs2, cs1, c);
		if (c == 6174 ||c==0)break;
		//printf("%4d",c);
		memset(str, 0, 5);
		//itoa(c, str, 10);
		sprintf(str, "%04d", c);
	}
	//printf();

	return 0;
}