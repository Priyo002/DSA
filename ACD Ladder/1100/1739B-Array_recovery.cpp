#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;

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
	vector<int> d(n), a(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	a[0] = d[0];
	for (int i = 1; i < n; i++) {

		int k1 = d[i] + a[i - 1];
		int k2 = -d[i] + a[i - 1];
		if (k1 != k2 && k1 > 0 && k2 >= 0) {
			//cout << k1 << " " << k2 << " ";
			cout << -1 << endl;
			return ;
		}

		a[i] = k1;

	}
	for (auto x : a) {
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