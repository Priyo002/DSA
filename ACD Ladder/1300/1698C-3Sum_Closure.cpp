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

	vector<int> pos, neg, a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) neg.push_back(x);
		else if (x > 0) pos.push_back(x);
		else {
			if (a.size() < 2)
				a.push_back(x);
		}
	}
	if (pos.size() > 2 || neg.size() > 2) {
		cout << "NO" << endl;
		return;
	}
	for (auto x : pos) a.push_back(x);
	for (auto x : neg) a.push_back(x);

	n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				bool flag = false;
				for (int l = 0; l < n; l++) {
					if (a[i] + a[j] + a[k] == a[l]) flag = true;
				}
				if (!flag) {
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	cout << "YES" << endl;
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