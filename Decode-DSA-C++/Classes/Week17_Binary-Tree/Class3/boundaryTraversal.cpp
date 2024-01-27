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

Node* construct(int arr[], int n) {
	queue<Node*> q;
	Node * root = new Node(arr[0]);
	q.push(root);
	int i = 1;
	int j = 2;
	while (q.size() && i < n) {
		Node* temp = q.front();
		q.pop();
		Node* l;
		Node* r;
		if (arr[i] != INT_MIN) l = new Node(arr[i]);
		else l = NULL;

		if (j != n && arr[j] != INT_MIN) r = new Node(arr[j]);
		else r = NULL;

		temp->left = l;
		temp->right = r;

		if (l) q.push(l);
		if (r) q.push(r);

		i += 2;
		j += 2;
	}
	return root;
}

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

void leftBoundary(Node * root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) return;
	cout << root->val << " ";
	leftBoundary(root->left);
	if (root->left == NULL) leftBoundary(root->right);
}
void bottomBoundary(Node * root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL)
		cout << root->val << " ";
	leftBoundary(root->left);
	leftBoundary(root->right);
}
void rightBoundary(Node * root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) return;
	leftBoundary(root->right);
	if (root->right == NULL)
		leftBoundary(root->left);
	cout << root->val << " ";
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, INT_MIN, 16, INT_MIN, 17, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
	int n = sizeof(arr) / sizeof(int);
	//construct
	Node* root = construct(arr, n);

	//level_OrderPrint(root);
	leftBoundary(root);
	bottomBoundary(root);
	rightBoundary(root->right);

	//boundary(root);


}