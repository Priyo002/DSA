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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long s = accumulate(a.begin(), a.end(), 0ll), cur = 0;
	long long ans = 1;
	for (int i = 0; i < n - 1; i++) {
		cur += a[i], s -= a[i];
		ans = max(ans, __gcd(s, cur));
	}
	cout << ans << "\n";
}

int main() {

	init();

	ll t;
	cin >> t;
	while (t--)
		solve();

}