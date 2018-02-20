
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
#include <set>
using namespace std;
int n = 0;
const string day[] = {
 "",
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
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string D;
	int len = min(s1.size(), s2.size());
	bool flag = false;
	int H = 0;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if ((s1[i]>='A'&&s1[i]<='G') && s1[i] == s2[i]) {
			
		D = day[s1[i] - 'A' + 1];
		break;
		}
		
	}

	for (int i = 0; i < len; i++) {
		if (s1[i] == s2[i]&&(!flag) &&  (s1[i] >= 'A'&&s1[i] <= 'N')) {
			flag = true;
			continue;
		}
		if(flag)
		if (s1[i] == s2[i]  && (isdigit(s1[i])||( s1[i] >= 'A'&&s1[i] <= 'N'))){
			if (flag) {
				if (isdigit(s1[i])) {
					H = s1[i] - '0';
				}
				if (isalpha(s1[i])) {
					H = s1[i] - 'A' + 10;
				}
			}
			break;
		}
	}
	
	len = min(s3.size(), s4.size());
	int M;
	for (int i = 0; i < len; i++) {
		
		if (s3[i] == s4[i]&&(isalpha(s3[i]))) {
			M = i;
			break;
		}
	}

	printf("%s %02d:%02d",D.c_str(),H,M);
	//printf();

	return 0;
}
