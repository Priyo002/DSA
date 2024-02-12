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

int n;
vector<vector<int>> adj;
vector<int> subtree;

void dfs(int src, int parent) {
	subtree[src] = 1;

	for (auto u : adj[src]) {
		if (u == parent) continue;
		dfs(u, src);
		subtree[src] += subtree[u];

	}
}

int dfs2(int src, int parent) {
	int mx = 0;
	int node = 0;

	for (auto u : adj[src]) {
		if (u == parent) continue;

		if (subtree[u] > mx) {
			mx = max(mx, subtree[u]);
			node = u;
		}
	}

	if (mx <= n / 2) {
		return src;
	}
	else {
		return dfs2(node, src);
	}
}

void solve() {

	cin >> n;
	adj.resize(n + 1, vector<int>());
	subtree.resize(n + 1);
	int k = n - 1;
	while (k--) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);

	}

	dfs(1, 0);
	cout << dfs2(1, 0) << endl;
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