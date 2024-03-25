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

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int cnt = 0;
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		if (i == arr[i])
			a.push_back(arr[i]);
	}
	int k = 0;
	for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << " ";
		if (i < a.size() - 1) {
			if (a[i] + 1 == a[i + 1]) {
				k++;
				i++;
			}
		}
	}

	cout << a.size() - k << endl;
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