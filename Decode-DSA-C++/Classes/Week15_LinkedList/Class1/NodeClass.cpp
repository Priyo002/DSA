#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int val) {
		this->val = val;
		this->next = NULL;//By default
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	Node a(10);
	Node b(20);
	Node c(30);
	Node d(40);
	a.next = &b;
	b.next = &c;
	c.next = &d;

	Node temp = a;

	while (true) {
		cout << temp.val << " ";
		if (temp.next == NULL) break;
		temp = *(temp.next);
	}

	return 0;
}