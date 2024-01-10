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
	vector<char> arr(6);
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 6; i++) {
		char ch = arr[i];
		if (ch == 'W') {
			int cnt = 0;
			int j = i;
			while (j < 6 && arr[j] == ch) {
				cnt++;
				j++;
			}
			if (cnt >= 3) {
				cout << "YES" << endl;
				return;
			}
			i = j - 1;
		}
	}
	cout << "NO" << endl;
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