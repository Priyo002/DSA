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

vector<list<int>> graph;
vector<int> dp;
int f(int node) {
	if (graph[node].size() == 0) return 0;
	if (dp[node] != -1) return dp[node];
	int mx = INT_MIN;
	for (auto neighbour : graph[node]) {
		mx = max(mx, 1 + f(neighbour));
	}
	return dp[node] = mx;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int v, e;
	cin >> v >> e;
	graph.clear();
	graph.resize(v + 1, list<int>());
	while (e--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	dp.clear();
	dp.resize(v + 1, -1);
	int ans = 0;
	for (int i = 1; i <= v; i++) {
		ans = max(ans, f(i));
	}
	cout << ans;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}