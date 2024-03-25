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

unordered_map<int, list<int>> graph;

int ans = 0;

string s;

pair<int, int> dfs(int src, vector<bool>& visited) {

	int b = 0, w = 0;

	if (s[src - 1] == 'W') w++;
	else b++;

	visited[src] = true;

	for (auto node : graph[src]) {
		if (!visited[node]) {
			pair<int, int> temp = dfs(node, visited);
			w += temp.first;
			b += temp.second;
		}
	}

	if (w == b) {
		ans++;
	}

	return {w, b};


}

void solve() {
	int n;
	cin >> n;

	ans = 0;
	graph.clear();

	int u = 2;

	for (int i = 1; i <= n - 1; i++) {
		int v;
		cin >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
		u++;
	}

	cin >> s;


	vector<bool> visited(n + 1, false);

	dfs(1, visited);

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