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

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		string str = "";
		str.push_back(s[i]);
		for (int j = i + 1; j < s.size(); j++) {
			str.push_back(s[j]);
			int k = stoi(str);
			if (isPrime(k)) {
				cout << k << endl;
				return;
			}
			str.pop_back();
		}
	}
	cout << -1 << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}