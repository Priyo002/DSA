#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

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
	if (n == 1) {
		cout << 1 ;
		return;
	}
	if (n <= 3) {
		cout << "NO SOLUTION";
		return;
	}
	vector<int> arr;
	for (int i = 2; i <= n; i += 2) {
		arr.pb(i);
	}
	for (int i = 1; i <= n; i += 2) {
		arr.pb(i);
	}

	for (auto x : arr) cout << x << " ";
}

int32_t main() {

	init();

	solve();

}