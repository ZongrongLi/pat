// 限定范围为 A~G  A~N  不能判定A~Z 
// 仔细读题意  第二组字符串 只要是字谜就行
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
string day[7] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};

int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0;
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int f = 0;
	int cnt = 0;
	int a=0, b=0;
	int len = min(s1.size(),s2.size());
	while (cnt<len)
	{
		if (s1.at(cnt) == s2.at(cnt)) {
			if (
				!((s1[cnt] >= 'A') &&
				(s1[cnt] <= 'G')
			     )
				) {
				cnt++;
				continue;
			}
			a = s1.at(cnt) - 'A';
			break;
		}
		cnt++;
	}
	cnt++;
	while (cnt<len)
	{
		
		if (s1.at(cnt) == s2.at(cnt)) {
			if ((s1[cnt] >= 'A') && (s1[cnt] <= 'N')) {
				b = s1.at(cnt) - 'A' + 10;
				break;
			}
			else if (isdigit(s1[cnt])) {
				b = s1.at(cnt) - '0';
				break;
			}
		}
		cnt++;
	}
	cnt = 0;
	len = min(s3.size(), s4.size());
	while (cnt<len)
	{
		if ( (s3.at(cnt) == s4.at(cnt) ) &&   ( isalpha(s3[cnt]) )) {
			break;
		}
		
		cnt++;
	}
	printf("%s %02d:%02d",day[a].c_str(),b,cnt);
	
	//printf();

	return 0; 
}