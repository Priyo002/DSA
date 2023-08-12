#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n), b, c;
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != maxi)
			b.push_back(arr[i]);
	}
	int bs = b.size();
	int cs = n - b.size();
	while (cs--) {
		c.push_back(maxi);
	}
	if (b.size() == 0) {
		cout << -1 << endl;
		return;
	}
	cout << b.size() << " " << c.size() << endl;
	for (auto x : b) {
		cout << x << " ";
	}
	cout << endl;
	for (auto x : c) {
		cout << x << " ";
	}
	cout << endl;

}

int main() {

	init();

	ll t;
	cin >> t;
	while (t--)
		solve();

}