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
const int m = 998244353;
void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}


vector<int> a;
int n;
unordered_map<string, int> mp;
int f(int l, int r) {
	int temp = 0;
	for (int i = r; i >= l; i--) {
		string k = to_string(l) + to_string(i);
		if (mp.find(k) != mp.end()) {
			temp ^= mp[k];
			break;
		}
		else temp ^= a[i];

	}
	mp.clear();
	string s = to_string(l) + to_string(r);
	mp[s] = temp;
	return temp;
}
void solve() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			ans = (ans % m) + (((r - l + 1) % m) * (f(l, r) % m)) % m;
		}
	}
	cout << ans % m << endl;
	//cout << mp.size() << endl;
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	solve();
	//cout << f1(1, 1);
	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}