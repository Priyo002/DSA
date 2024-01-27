#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif


	//Morris Traversal = Inorder Traversal (Iterative Approach)
	TreeNode* curr = root;

	while (curr) {
		if (curr->left) { //Find Predecessor
			TreeNode* pred = curr->left;
			while (pred->right && pred->right != curr) {
				pred = pred->right;
			}
			if (pred->right == NULL) {//link
				pred->right = curr;
				curr = curr->left;
			}
			if (pred->right == curr) { //unlink
				pred->right = NULL;
				cout << curr->val << " ";//visit
				curr = curr->right;
			}
		}
		else { //visit right subtree
			cout << curr->val << " ";//visit
			curr = curr->right;
		}
	}
}