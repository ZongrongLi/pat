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

const string digit[10]{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
int main() {
	freopen("./test.txt", "r", stdin);
	char s[1010];
	fgets(s,1010,stdin);
	int len = strlen(s);
	if (s[len - 1] == '\n') {
		s[len - 1] = '\0';
		len--;
	}
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += (s[i] - '0');
	}
	if (sum == 0) {
		cout << digit[0];
		return 0;
	}
	vector<string> ve;
	while (sum!=0)
	{
		ve.push_back(digit[sum%10]);
		sum /= 10;
	}
	for (int i =  ve.size()-1;i>=0; i--)
	{
		if (i != 0)
			cout << ve[i] << " ";
		else cout << ve[i];
	}
	//printf();

	return 0;
}
