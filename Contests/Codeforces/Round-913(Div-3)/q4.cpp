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

#define pp pair<int,int>

void solve() {
	int n;
	cin >> n;
	priority_queue<pp, vector<pp>> a, b, c;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push({x, i});
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		b.push({x, i});
	}

	for (int i = 0; i < n; i++) {
		cin >> x;
		c.push({x, i});
	}
	int ans = INT_MIN;

	while (a.size()) {
		auto curr = a.top();
		a.pop();
		int sum = curr.first;
		int idx1 = curr.second;

		auto temp = b.top();
		bool flag = false;
		if (temp.second == curr.second) {
			b.pop();
			flag = true;
		}
		sum += b.top().first;
		int idx2 = b.top().second;
		if (flag) b.push(temp);

		vector<pp> k;
		while (c.size() && (c.top().second == idx1 || c.top().second == idx2)) {
			k.push_back(c.top());
			c.pop();
		}
		sum += c.top().first;
		for (auto m : k) c.push(m);

		ans = max(ans, sum);

	}

	cout << ans << endl;

}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}