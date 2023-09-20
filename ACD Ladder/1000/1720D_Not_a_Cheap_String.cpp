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
	string s;
	cin >> s;
	int n;
	cin >> n;
	unordered_map<char, int> mp;
	priority_queue<char> pq;
	int sum = 0;
	for (auto ch : s) {
		mp[ch]++;
		pq.push(ch);
		sum += (ch - 'a' + 1);
	}
	if (sum <= n) {
		cout << s << endl;
		return;
	}
	while (sum > n && pq.size() > 0) {
		char ch = pq.top();
		pq.pop();
		sum -= (ch - 'a' + 1);
		//cout << sum << endl;
		mp[ch]--;
		if (mp[ch] == 0) mp.erase(ch);
	}
	if (pq.size() == 0) {
		cout << endl;
		return;
	}
	string ans = "";
	for (auto i : s) {
		if (mp.find(i) != mp.end()) {
			ans.push_back(i);
			mp[i]--;
			if (mp[i] == 0) mp.erase(i);
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