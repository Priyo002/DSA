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
	int n, q;
	cin >> n >> q;

	int sum = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		sum += x;
	}

	bool flag = false;
	int last = 0;
	unordered_set<int> idx;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, val;
			cin >> i >> val;
			if (!flag) {
				sum -= arr[i - 1];
			}
			else {
				if (idx.count(i - 1)) sum -= arr[i - 1];
				else sum -= last;
			}
			if (flag) idx.insert(i - 1);
			sum += val;
			arr[i - 1] = val;
		}
		else {
			int val;
			cin >> val;
			last = val;
			flag = true;
			idx.clear();
			sum = val * n;
		}
		cout << sum << endl;
	}
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