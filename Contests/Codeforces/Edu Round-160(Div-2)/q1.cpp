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

	string s1 = "";
	string s2 = "";
	s1 += s[0];
	int i = 1;
	while (i < s.size() && s[i] == '0') {
		s1 += s[i];
		i++;
	}
	while (i < s.size()) {
		s2 += s[i];
		i++;
	}
	if (s2.size() == 0) {
		cout << -1 << endl;
		return;
	}
	int a = stoi(s1), b = stoi(s2);
	if (a < b) {
		cout << a << " " << b << endl;
		return ;
	}
	cout << -1 << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}