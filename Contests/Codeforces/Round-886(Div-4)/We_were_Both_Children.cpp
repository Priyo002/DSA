#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int>Hash;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		Hash[x]++;
	}
	std::vector<int> a(n + 1, 0);
	for (auto [u, v] : Hash) {
		for (int i = u; i <= n; i += u) {
			a[i] += v;
		}
	}
	cout << *max_element(a.begin(), a.end()) << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
