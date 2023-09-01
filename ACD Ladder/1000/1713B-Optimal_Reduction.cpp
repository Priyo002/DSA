#include<bits/stdc++.h>
using namespace std;

#define int long long
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int flag = 0;
	int inc = 0, dec = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) {
			if (dec == 0) {
				inc = 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		else if (a[i] < a[i - 1]) {
			dec = 1;
		}
	}
	if (flag) cout << "NO";
	else cout << "YES";
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}