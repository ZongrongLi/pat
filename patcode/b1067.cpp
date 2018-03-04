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

int main() {
	freopen("./test.txt", "r", stdin);
	string ps;
	cin >> ps;
	scanf("%d", &n);
	getchar();
	int cnt = 0;
	while (1) {
		cnt++;
		string s;
		getline(cin, s);
	//	cout << "--" << s << endl;
		if (s == "#")break;
		if (cnt >= n&&s!=ps) {
			cout << "Wrong password: " << s << endl;
			cout << "Account locked"<<endl ;
			break;;
		}
		if (s == ps) {
			cout << "Welcome in" <<endl;
			break;
		}
		else {
			cout<<"Wrong password: " <<s<< endl;
		}

	}
	//printf();

	return 0;
}


//#include <iostream>
//#include<string>
//using namespace std;
//int main() {
//	freopen("./test.txt", "r", stdin);
//	string password, temp;
//	int n, cnt = 0;
//	cin >> password >> n;
//	getchar();
//	while (1) {
//		getline(cin, temp);
//		if (temp != "#") {
//			cnt++;
//		}
//		else {
//			break;
//		}
//		if (cnt <= n && temp == password) {
//			cout << "Welcome in";
//			break;
//		}
//		else if (cnt <= n && temp != password) {
//			cout << "Wrong password: " << temp << endl;
//			if (cnt == n) {
//				cout << "Account locked";
//				break;
//			}
//		}
//	}
//	return 0;
//}