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

class DLL { //User defined data structure
public:
	Node* head ;
	Node* tail ;
	int size;
	DLL() {
		head = tail = NULL;
		size = 0;
	}
	void insertAtBegining(int val) {
		Node * temp = new Node(val);
		if (size == 0) head = temp;
		else {
			temp -> next = head;
			head->prev = temp;
			head = temp;
		}
		size++;
	}
	void insertAtTail(int val) {
		Node* temp = new Node(val);
		if (size == 0) head = tail = temp;
		else {
			tail-> next = temp;
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}
	void insertAtIdx(int idx, int val) {
		if (idx == 0) insertAtBegining(val);
		else if (idx == size ) insertAtTail(val);
		else if (idx < 0 || idx > size) {
			cout << "Invalid Index" << endl;
		}

		else {
			Node *t = new Node(val);
			Node *temp = head;
			for (int i = 1; i <= idx - 1; i++) {
				temp = temp->next;
			}
			t->next = temp->next;
			temp->next = t;
			t->prev = temp;
			t->next->prev = t;
			size++;
		}
	}
	int getIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "Invalid Index ";
			return -1;
		}
		else if (idx == 0) return head->val;
		else if (idx == size - 1) return tail->val;
		else {
			Node *temp = head;
			for (int i = 1; i <= idx ; i++) {
				temp = temp -> next;
			}
			return temp->val;
		}
	}
	void deleteAtHead() {
		if (size == 0) cout << "List is Empty!";
		else {
			head = head->next;
			if (head != NULL)
				head->prev = NULL;
			if (head == NULL)
				tail = NULL;
			size--;
		}
	}
	void deleteAtTail() {
		if (size == 0) cout << "List is Empty";
		else {
			tail = tail->prev;
			tail->next = NULL;
			size--;
		}
	}
	void deleteAtIdx(int idx) {
		if (idx < 0 || idx >= size) cout << "Invalid Index";
		else if (idx == 0) deleteAtHead();
		else if (idx == size - 1) deleteAtTail();
		else {
			Node *temp = head;
			for (int i = 1; i <= idx - 1; i++) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
			size--;
		}
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



	DLL ll;
	for (int i = 1; i <= 5; i++)
		ll.insertAtTail(10 * i);

	ll.display();
	ll.insertAtTail(110);
	ll.insertAtBegining(0);
	ll.insertAtIdx(2, -40);
	ll.display();

	cout << ll.getIdx(3) << endl;

	ll.deleteAtHead();
	ll.display();
	ll.deleteAtTail();
	ll.display();
	ll.deleteAtIdx(3);
	ll.display();

	return 0;
}