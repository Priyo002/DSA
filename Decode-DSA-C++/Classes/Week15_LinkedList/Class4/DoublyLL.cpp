#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *prev;
	Node(int val) {
		this->val = val;
		next = NULL;
		prev = NULL;
	}
};

void display(Node *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void displayInReverse(Node *tail) {
	while (tail) {
		cout << tail->val << " ";
		tail = tail->prev;
	}
	cout << endl;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Node *a = new Node(0);
	Node *head = a;
	for (int i = 1; i <= 10; i++) {
		Node *temp = new Node(10 * i);
		a->next = temp;
		temp->prev = a;
		a = a->next;
	}
	Node *tail = a;

	// Node *a = new Node(10);
	// Node *b = new Node(20);
	// Node *c = new Node(30);
	// Node *d = new Node(40);
	// Node *e = new Node(50);

	// a->next = b;
	// b->next = c;
	// c->next = d;
	// d->next = e;

	// e->prev = d;
	// d->prev = c;
	// c->prev = b;
	// b->prev = a;

	display(head);
	displayInReverse(tail);

}