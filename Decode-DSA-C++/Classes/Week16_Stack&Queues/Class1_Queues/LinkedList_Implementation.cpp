#include<bits/stdc++.h>
using namespace std;

class Node { //User defined data type
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Queue { //User defined data structure
public:
	Node* head ;
	Node* tail ;
	int s;
	Queue() {
		head = tail = NULL;
		s = 0;
	}
	void push(int val) {
		Node* temp = new Node(val);
		if (s == 0) head = tail = temp;
		else {
			tail-> next = temp;
			tail = temp;
		}
		s++;
	}

	void pop() {
		if (s == 0) cout << "Queue is Empty!";
		else {
			Node *temp = head;
			head = head->next;
			s--;
			delete(temp);
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
	void display() {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
	int size() {
		return s;
	}
};
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	q.display();
	q.pop();
	q.display();
	cout << q.front() << endl;
	cout << q.size() << endl;

}