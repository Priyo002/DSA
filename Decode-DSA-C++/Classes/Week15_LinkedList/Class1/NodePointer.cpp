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

//Recursively
void display2(Node *head) {
	if (head == NULL) return;
	cout << head->val << " ";
	display2(head->next);
}

void display(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

int size(Node *head) {
	Node* temp = head;
	int cnt = 0;
	while (temp != NULL) {
		temp = temp->next;
		cnt++;
	}
	return cnt;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Node *a = new Node(10);
	Node *b = new Node(20);
	Node *c = new Node(30);
	Node *d = new Node(40);
	Node *e = new Node(50);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	display(a);
	cout << endl;
	cout << size(a);
	cout << endl;
	display(a);

}