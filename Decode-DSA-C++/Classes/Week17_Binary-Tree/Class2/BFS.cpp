#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

void LevelOrder_Queue(Node *root) {//BFS
	queue<Node*> q;
	q.push(root);
	while (q.size()) {
		Node* temp = q.front();
		q.pop();
		cout << temp->val << " ";

		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right)
			q.push(temp->right);

	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(5);
	Node *f = new Node(6);
	Node *g = new Node(7);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	LevelOrder_Queue(a);


}