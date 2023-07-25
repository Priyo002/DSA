#include<bits/stdc++.h>
using namespace std;

bool isSame(vector<int>&a, vector<int>&b) {
	vector<int> k1 = a, k2 = b;
	sort(k1.begin(), k1.end());
	sort(k2.begin(), k2.end());
	return k1 == k2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == a[a.size() - 1]) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}