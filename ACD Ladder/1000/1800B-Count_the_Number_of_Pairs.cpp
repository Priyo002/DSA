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
	int n, k, cnt = 0;
	cin >> n >> k;
	unordered_map<char, int> mp;
	char ch;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		if (islower(ch)) {
			char t1 = ch - 32;
			if (mp.count(t1)) {
				mp[t1]--;
				cnt++;
				if (mp[t1] == 0) mp.erase(t1);
			}
			else mp[ch]++;
		}
		else {
			char t1 = ch + 32;
			if (mp.count(t1)) {
				mp[t1]--;
				cnt++;
				if (mp[t1] == 0) mp.erase(t1);
			}
			else mp[ch]++;
		}
	}
	for (auto x : mp) {
		int t = x.second;
		while (t > 1 && k) {
			t -= 2;
			k--;
			cnt++;
		}
	}
	cout << cnt << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}