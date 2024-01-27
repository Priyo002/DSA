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

void product(Node * root, long long &prod) {
	if (root == NULL) return;
	prod *= root->val;
	product(root->left, prod);
	product(root->right, prod);
}

void mini(Node *root, int &mi) {
	if (root == NULL) return;
	mi = min(mi, root->val);
	mini(root->left, mi);
	mini(root->right, mi);
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
	int n = INT_MIN;
	int arr[] = {1, 2, 2, 3, 3, n, n, 4, 4};
	int n1 = sizeof(arr) / sizeof(int);
	//construct
	Node* root = construct(arr, n1);

	LevelOrder_Queue(root);
	cout << endl;
	long long prod = 1;
	product(root, prod);
	cout << prod << endl;

	int mi = INT_MAX;
	mini(root, mi);
	cout << mi << endl;

	cout << level(root->left) << endl;
	cout << level(root->right);


}