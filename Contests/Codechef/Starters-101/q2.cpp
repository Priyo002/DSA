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

int ops(string& str, string& k) {
	string res = "";
	int n = k.size();
	int j = str.size() - 1;
	while (n--) {
		res.push_back(str[j]);
		j--;
	}
	reverse(res.begin(), res.end());
	if (res == k) return 0;
	int sum = 0;
	for (int i = 0; i < res.size(); i++) {
		int t1 = (res[i] - '0') + ('9' - k[i]);
		int t2 = INT_MAX;
		if (k[i] >= res[i]) t2 = k[i] - res[i];
		sum += min(sum, min(t1, t2));
	}
	return sum;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s, k;
	cin >> s >> k;
	string str = "";
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		str.push_back(s[i]);
		if (str.size() >= m) {
			//cout << str << endl;
			ans = min(ans, ops(str, k));
		}
	}
	cout << ans << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}