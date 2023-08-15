#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
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
	unordered_set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}
	for (int i = 1; i <= n; i++) {
		if (st.find(i) == st.end()) continue;
		for (int j = i; j <= n; j *= 2) {
			cout << j << " ";
			st.erase(j);
		}
	}
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}