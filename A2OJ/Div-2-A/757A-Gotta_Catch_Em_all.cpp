#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	string s;
	cin >> s;
	unordered_map<char, int> mp;
	for (int i = 0; i < s.size(); i++) {
		mp[s[i]]++;
	}
	/*
	B-1
	u-2
	l-1
	a-2
	s-1
	r-1
	*/
	string str = "Bulbasr";
	int ans = INT_MAX;
	for (int i = 0; i < str.size(); i++) {
		if (mp.find(str[i]) != mp.end()) {
			if (str[i] == 'u' || str[i] == 'a') {
				ans = min(ans, mp[str[i]] / 2);
			}
			else ans = min(ans, mp[str[i]]);
		}
		else {
			cout << 0;
			return;
		}
	}
	cout << ans;
	return;
}

int main() {

	init();


	solve();

}