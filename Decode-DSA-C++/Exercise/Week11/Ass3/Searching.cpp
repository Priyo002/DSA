#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int idx, int key) {
	if (idx == v.size()) {
		return -1;
	}
	if (v[idx] == key) {
		return idx;
	}
	else {
		search(v, idx + 1, key);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	vector<int> v = {1, 2, 3, 8, 10, 9};
	int key;
	cin >> key;
	int ans = search(v, 0, key);
	cout << ans;
}