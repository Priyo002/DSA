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
	vector<int> v(n), id(n), ans(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> id[i];
	}
	for (int i = 0; i < 3; i++) {
		vector<int> past_order(n);
		for (int j = 0; j < n; j++) {
			// -1 because the shuffle input starts from 1
			past_order[j] = id[v[j] - 1];
		}
		id = past_order;
	}

	for (auto x : id) cout << x << endl;

}


int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}