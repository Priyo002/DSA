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
	bool flag = false, caps = true;
	if (isupper(s[0])) flag = true;
	for (int i = 1; i < s.size(); i++) {
		if (isupper(s[i])) {
			caps = true;
		}
		else {
			caps = false;
			break;
		}
	}
	if (flag && caps) {
		cout << (char) (s[0] + 32);
		for (int i = 1; i < s.size(); i++) {
			cout << (char)(s[i] + 32);
		}
	}
	else if (flag == false && caps) {
		cout << (char)(s[0] - 32);
		for (int i = 1; i < s.size(); i++) {
			cout << (char)(s[i] + 32);
		}
	}
	else cout << s;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}