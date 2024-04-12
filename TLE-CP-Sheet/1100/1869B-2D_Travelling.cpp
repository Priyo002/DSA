#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end())
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
	int n, k, a, b;
	cin >> n >> k >> a >> b;


	vector<pair<int, int>> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	if (a <= k && b <= k) {
		cout << 0 << endl;
		return;
	}

	int ans =  abs(arr[a].first - arr[b].first) + abs(arr[a].second - arr[b].second);
	int dist1 = INF, dist2 = INF;
	for (int i = 1; i <= k; i++) {
		dist1 = min(dist1, abs(arr[i].first - arr[a].first) + abs(arr[i].second - arr[a].second));
		dist2 = min(dist2, abs(arr[i].first - arr[b].first) + abs(arr[i].second - arr[b].second));
	}

	cout << min(ans, (dist1 + dist2)) << endl;

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