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
int v, e;

int bfs(int src) {
	vector<bool> visited(v + 1, false);
	visited[src] = true;

	queue<int> qu;
	for (auto curr : graph[src]) {
		qu.push(curr);
	}
	int ans = 0;
	while (qu.size()) {
		int cnt = qu.size();
		while (cnt--) {
			auto curr = qu.front();
			qu.pop();
			visited[curr] = true;
			for (auto neighbour : graph[curr]) {
				if (!visited[neighbour]) {
					qu.push(neighbour);
				}
			}
		}
		ans++;
	}
	return ans;
}

void solve() {
	cin >> v >> e;
	graph.clear();
	graph.resize(v + 1, list<int>());

	while (e--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int mn = INT_MAX;
	int vertex = 0;
	for (int i = 1; i <= v; i++) {
		int cnt = bfs(i);
		//cout << i << "->" << cnt << endl;
		if (cnt < mn) {
			mn = cnt;
			vertex = i;
		}
	}

	int x = graph[vertex].size();
	int y = (v - x - 1) / x;

	cout << x << " " << y << endl;

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