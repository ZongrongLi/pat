
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>

class node {
public:
	int key;
	int next;
	int add;
	bool operator <(node &T) {
		return this->key < T.key;
	}
};
node A[100005];
node B[100005];
int main() {
	freopen("./test.txt", "r", stdin);
	int n = 0, first = 0;
	scanf("%d %d", &n, &first);
	int top = -1;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		node t;
		scanf("%d %d %d",&a,&b,&c);
		t.key = b;
		t.add = a;
		t.next = c;
		//A[++top] = t;
		B[a] = t;

	}
	int  p = first;
	while (p!=-1)
	{
		A[++top] = B[p];
		p = B[p].next;	
	}
	std::sort(A, A + top+1);
	if (top == -1) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", top + 1,A[0].add);
	
	for (int i =0; i < top; i++) {
		//A[i].next = A[i + 1].add;
		printf("%05d %d %05d\n", A[i].add, A[i].key, A[i+1].add);
	}
	
	printf("%05d %d -1", A[top].add, A[top].key);

	return 0;
}