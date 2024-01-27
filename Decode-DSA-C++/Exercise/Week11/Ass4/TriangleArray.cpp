#include<bits/stdc++.h>
using namespace std;

void sum(vector<int> &v, int idx) {
	if (v.size() == 1) {
		return;
	}
	vector<int> ans;
	for (int i = idx; i < v.size() - 1; i++) {
		ans.push_back(v[i] + v[i + 1]);
	}
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	sum(ans, idx);


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {5, 4, 3, 2, 1};
	vector<int> ans;
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	sum(v, 0);
}