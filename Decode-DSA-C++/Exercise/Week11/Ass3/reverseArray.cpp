#include<bits/stdc++.h>
using namespace std;

void printreverse(vector<int> &v, int idx) {
	if (idx == v.size() - 1) {
		cout << v[idx];
		return;
	}
	printreverse(v, idx + 1);
	cout << v[idx];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {1, 2, 3, 4, 5};
	printreverse(v, 0);
}