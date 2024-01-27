#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pp pair<int,int>

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

/*
Q: Given an undirected weighted graph, along with
a source and destination. Find the shortest path between
the source and destination in terms of sum of edge weights.
*/


vector<list<pp>> graph;
void add_edge(int u, int v, int wt, bool bi_dir = true) {
	graph[u].push_back({v, wt});
	if (bi_dir) {
		graph[v].push_back({u, wt});
	}
}

void prims(int src, int n) {
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	unordered_set<int> visited;
	vector<int> via(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) mp[i] = INT_MAX;
	pq.push({0, src});
	mp[src] = 0;

	while (pq.size()) {
		pp curr = pq.top();
		pq.pop();
		if (visited.count(curr.second)) {
			continue;
		}
		visited.insert(curr.second);
		for (auto neighbour : graph[curr.second]) {
			if (!visited.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second) {
				pq.push({neighbour.second, neighbour.first});
				via[neighbour.first] = curr.second;
				mp[neighbour.first] = mp[curr.second] + neighbour.second;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << " " << mp[i] << " " << via[i] << endl;
	}
}

int32_t main() {

	init();
	//1-based indexing
	int n, m;
	cin >> n >> m;
	graph.resize(n + 1, list<pp>());
	while (m--) {
		int u, v, wt;
		cin >> u >> v >> wt;
		add_edge(u, v, wt);
	}
	int src;
	cin >> src;
	prims(src, n);

	return 0;


}