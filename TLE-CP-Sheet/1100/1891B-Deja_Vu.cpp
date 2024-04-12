#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
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
	int n, q;
	cin >> n >> q;

	unordered_set<int> st;

	vector<int> arr(n), brr(q);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < q; i++) {
		cin >> brr[i];
		st.insert(brr[i]);
	}

	for (auto x : brr) {
		if (st.count(x) == 0) continue;
		st.erase(x);
		int y = (1 << x);
		for (int i = 0; i < n; i++) {
			if (arr[i] % y == 0) {
				arr[i] += (1 << (x - 1));
			}
		}
	}

	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}