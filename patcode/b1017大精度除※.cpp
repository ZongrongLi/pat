
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


int main() {
	freopen("./test.txt", "r", stdin);
	string a;
	cin >> a;
	int b;
	scanf("%d", &b);
	string ans;
	int c = 0;
	for (int i = 0; i < a.size(); i++) {
		ans.push_back(((a[i]-'0')+c*10)/b  +'0');
		c = ((a[i] - '0') + c * 10) % b;
	}
	
	int i = 0;
	while (ans[i] == '0')i++;
	ans = ans.substr(i, ans.size() - i);
	//printf();
	if(ans.size()==0)cout << "0 " << a;
	else
		cout << ans<<" " << c;
	return 0;
}
