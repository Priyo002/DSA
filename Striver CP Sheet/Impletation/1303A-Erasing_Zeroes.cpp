#include<bits/stdc++.h>
using namespace std;

#define int long long int
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
	string str;
	cin >> str;
	string s = "";
	bool flag = true;
	int cnt = 0, idx = -1, idx2 = -1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1' && flag == true) {
			idx = i;
			flag = false;
		}
		if (str[i] == '1') {
			idx2 = i;
		}
	}
	if (idx == -1) {
		cout << 0 << endl;
		return;
	}
	for (int i = idx; i <= idx2; i++) {
		if (str[i] == '0') cnt++;
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