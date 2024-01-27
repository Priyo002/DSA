#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
		next = NULL;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Node *head = new Node(10);
	Node *temp = head;
	for (int i = 2; i <= 10; i++) {
		Node *a = new Node(i * 10);
		temp->next = a;
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	//Making loop in the linked list
	temp = head;
	while (temp->val != 80) {
		temp = temp->next;
	}
	temp->next = head;
	Node * slow = head;
	Node * fast = head;
	while (slow != fast && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	int cnt = 1;
	slow = slow->next;
	while (slow != fast) {
		slow = slow->next;
		cnt++;
	}
	cout << endl;
	cout <<  "Length of the loop " << cnt;

}