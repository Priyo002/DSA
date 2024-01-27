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

void topview(Node* root) {
	unordered_map<int, int> m;
	queue< pair<Node*, int> >q;
	pair<Node*, int> r;
	r.first = root;
	r.second = 0;
	q.push(r);
	int minLevel = INT_MAX;
	int maxLevel = INT_MIN;
	while (q.size() > 0) {
		Node* temp = (q.front()).first;
		int level = (q.front()).second;
		q.pop();
		if (m.find(level) == m.end()) {
			m[level] = temp->val;
		}
		if (temp->left) {
			pair<Node*, int> p;
			p.first = temp->left;
			p.second = level - 1;
			q.push(p);
		}
		if (temp->right) {
			pair<Node*, int> p;
			p.first = temp->right;
			p.second = level + 1;
			q.push(p);
		}
		for (auto x : m) {
			int level = x.first;
			minLevel = min(minLevel, level);
			maxLevel = max(maxLevel, level);
		}
	}
	for (int i = minLevel; i <= maxLevel; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
	int n = sizeof(arr) / sizeof(int);
	//construct
	Node* root = construct(arr, n);
	//LevelOrder_Queue(root);

	topview(root);

}