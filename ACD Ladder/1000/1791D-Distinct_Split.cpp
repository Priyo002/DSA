#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

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
	int n, i;
	cin >> n;
	string s;
	cin >> s;
	vector<int> prefix(n, 0), suffix(n, 0);
	unordered_set<char> st;
	for (i = 0; i < s.size(); i++) {
		st.insert(s[i]);
		prefix[i] = st.size();
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		st.insert(s[i]);
		suffix[i] = st.size();
	}
	int ans = 0;
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = prefix[i] + suffix[i + 1];
		mx = max(mx, ans);
	}
	cout << mx << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}