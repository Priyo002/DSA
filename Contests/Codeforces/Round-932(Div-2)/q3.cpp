#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end())
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
	int n, l, ans = 0;

	cin >> n >> l;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), [&](pair<int, int>&a, pair<int, int>&b) {
		return a.second < b.second;
	});

	for (int i = 0; i < n; i++) {

		priority_queue<int> pq;
		int sum = 0;

		for (int j = i; j < n; j++) {
			pq.push(arr[j].first);
			sum += arr[j].first;

			while (pq.size() && sum + (arr[j].second - arr[i].second) > l) {
				sum -= pq.top();
				pq.pop();
			}

			ans = max(ans, (int)pq.size());
		}
	}
	cout << ans << endl;
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