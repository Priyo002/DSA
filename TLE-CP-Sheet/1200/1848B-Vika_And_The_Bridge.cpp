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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1), idx(n + 1, 0), gap(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	unordered_map<int, int> last;
	unordered_map<int, priority_queue<int>> mp;
	unordered_set<int> st;
	for (int i = 1; i <= n; i++) {
		int ele = arr[i];
		st.insert(ele);
		int gap = i - last[ele] - 1;
		mp[ele].push(gap);
		last[ele] = i;
	}

	int ans = INT_MAX;
	for (auto x : st) {
		mp[x].push(n - last[x]);
		int top = mp[x].top();
		mp[x].pop();
		int s = mp[x].top();

		ans = min(ans, max(top / 2, s));
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