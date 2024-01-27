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
void display(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* deleteNode(Node* head, Node* target) {
	if (head == target) {
		head = head->next;
		return head;
	}
	Node *temp = head;
	while (temp->next != target) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
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
	Node * head = a;
	display(head);
	head = deleteNode(a, c);
	display(head);
}