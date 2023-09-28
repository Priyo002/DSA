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
	int m, n, k;
	cin >> m >> n >> k;
	vector<string> arr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	for (auto str : arr) {
		string temp = "";
		temp += str[0];
		string ans = "";
		for (int i = 1; i < str.size(); i++) {
			if (temp.back() == str[i]) {
				temp += str[i];
			}
			else {
				for (int j = 0; j < k; j++) {
					ans += temp;
				}
				temp = "";
				temp += str[i];
			}
		}
		if (temp.size()) {
			for (int j = 0; j < k; j++)
				ans += temp;
		}
		for (int j = 0; j < k; j++)
			cout << ans << endl;
	}
}

int32_t main() {

	//init();
	// clock_t time_req;
	// time_req = clock();

	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
	solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}