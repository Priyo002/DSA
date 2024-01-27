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

void print_nthLevel(Node *root, int curr, int level) {
	if (root == NULL) return;
	if (curr == level) {
		cout << root->val << " ";
		return;
	}

	print_nthLevel(root->left, curr + 1, level);
	print_nthLevel(root->right, curr + 1, level);

}

int level(Node *root) {
	if (root == NULL) return 0;
	return 1 + max(level(root->left), level(root->right));
}

void level_OrderPrint(Node *root) {
	int n = level(root);
	for (int i = 1; i <= n; i++) {
		print_nthLevel(root, 1, i);
		cout << endl;
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

	level_OrderPrint(a);



}