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

void display(Node *root) {
	if (root == NULL) return;
	cout << root->val << " ";
	display(root->left);
	display(root->right);
}

int sum(Node *root) {
	if (root == NULL) return 0;
	return root->val + sum(root->left) + sum(root->right);
}
int maxInTree(Node *root) {
	if (root == NULL) return INT_MIN;

	return max({root->val, maxInTree(root->left), maxInTree(root->right)});
}
int size(Node *root) {
	if (root == NULL) return 0;
	return 1 + size(root->left) + size(root->right);
}
int level(Node *root) {
	if (root == NULL) return 0;
	return 1 + max(level(root->left), level(root->right));
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
	Node *h = new Node(10);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	g->right = h;

	display(a) ;
	cout << endl;
	cout << sum(a) << endl;
	cout << size(a) << endl;
	cout << maxInTree(a) << endl;
	cout << level(a) << endl;

}