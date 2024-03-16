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
int cnt = 1;
vector<pair<int, int>> arr;

//Eular tour

void dfs(int src, int level, vector<bool>& visited, unordered_map<int, list<int>>& graph) {
	visited[src] = true;

	arr.push_back({src, level});

	for (auto node : graph[src]) {
		if (visited[node]) continue;
		dfs(node, level + 1, visited, graph);
		arr.push_back({src, level});
	}
}

void solve() {
	cin >> n;

	unordered_map<int, list<int>> graph;

	vector<int> r(n + 1, 0);

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			r[x]++;
			graph[i + 1].push_back(x);
		}
	}
	arr.clear();
	vector<bool> visited(n + 1, false);
	dfs(1, 1, visited, graph);

	unordered_map<int, pair<int, int>> mp;

	for (int i = 0; i < arr.size(); i++) {
		if (mp.count(arr[i].first) == 0)
			mp[arr[i].first].first = i;
		mp[arr[i].first].second = i;
	}
	int q;
	cin >> q;
	cout << "Case " << cnt++ << ":" << endl;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int s = min(mp[a].first, mp[b].first), e = max(mp[a].second, mp[b].second);
		int ans = 0, mn = INT_MAX;
		for (int i = s; i <= e; i++) {
			if (arr[i].second <= mn) {
				ans = arr[i].first;
				mn = arr[i].second;
			}
		}
		cout << ans << endl;
	}
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