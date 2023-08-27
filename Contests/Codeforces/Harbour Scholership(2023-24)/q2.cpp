#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
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
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	if (k % 2 == 0)
	{
		sort(s);
		cout << s << endl;
		return;
	}

	vector<char> v;
	for (int i = 0; i < n; i += 2)
		v.pb(s[i]);

	sort(v);

	for (int i = 0, j = 0; i < n; i += 2)
		s[i] = v[j++];

	v.clear();
	for (int i = 1; i < n; i += 2)
		v.pb(s[i]);

	sort(v);

	for (int i = 1, j = 0; i < n; i += 2)
		s[i] = v[j++];

	cout << s << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}