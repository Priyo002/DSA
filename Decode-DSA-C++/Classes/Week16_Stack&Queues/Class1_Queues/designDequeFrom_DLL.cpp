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

class Deque { //User defined data structure
public:
	Node* head ;
	Node* tail ;
	int s;
	Deque() {
		head = tail = NULL;
		s = 0;
	}
	void pushFront(int val) {
		Node * temp = new Node(val);
		if (s == 0) head = temp;
		else {
			temp -> next = head;
			head->prev = temp;
			head = temp;
		}
		s++;
	}
	void pushBack(int val) {
		Node* temp = new Node(val);
		if (s == 0) head = tail = temp;
		else {
			tail-> next = temp;
			temp->prev = tail;
			tail = temp;
		}
		s++;
	}
	void popFront() {
		if (s == 0) cout << "List is Empty!";
		else {
			head = head->next;
			if (head != NULL)
				head->prev = NULL;
			if (head == NULL)
				tail = NULL;
			s--;
		}
	}
	void popBack() {
		if (s == 0) cout << "List is Empty";
		else {
			tail = tail->prev;
			tail->next = NULL;
			s--;
		}
	}
	int front() {
		if (s == 0) {
			cout << "Queue is Empty!";
			return -1;
		}
		return head->val;
	}
	int back() {
		if (s == 0) {
			cout << "Queue is Empty!";
			return -1;
		}
		return tail->val;
	}
	int size() {
		return s;
	}
	void display() {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Deque dq;
	dq.pushBack(10);
	dq.pushBack(20);
	dq.pushBack(30);
	dq.pushBack(40);
	dq.display();
	dq.popBack();
	dq.display();
	dq.popFront();
	dq.pushFront(100);
	dq.display();


	return 0;
}