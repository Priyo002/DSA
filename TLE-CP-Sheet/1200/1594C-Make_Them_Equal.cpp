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
	int n;
	cin >> n;
	char ch;
	cin >> ch;
	string str;
	cin >> str;

	set<int> st;
	for (int i = 0; i < n; i++) {
		if (str[i] != ch) {
			st.insert(i + 1);
		}
	}
	if (st.size() == 0) {
		cout << 0 << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			bool flag = true;
			for (int j = i; j <= n; j += i) {
				if (st.count(j)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << 1 << endl;
				cout << i << endl;
				return;
			}
		}

		cout << 2 << endl;
		cout << n - 1 << " " << n << endl;

	}
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