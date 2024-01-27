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

unordered_map<int, int> dijkstra(int src, int v) {//O(Vlogv+ElogV+V)
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	unordered_set<int> visited;
	vector<int> via(v);
	unordered_map<int, int> mp;

	for (int i = 0; i < v; i++) mp[i] = INT_MAX;//O(V)

	pq.push({0, src});
	mp[src] = 0;

	while (pq.size()) {//O((V+E)logV)
		pp curr = pq.top();
		pq.pop();
		if (visited.count(curr.second)) {
			continue;
		}
		visited.insert(curr.second);

		for (auto neighbour : graph[curr.second]) {//O(V+E)
			if (!visited.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second) {
				pq.push({mp[curr.second] + neighbour.second, neighbour.first});
				via[neighbour.first] = curr.second;
				mp[neighbour.first] = mp[curr.second] + neighbour.second;
			}
		}
	}

	return mp;
}

int32_t main() {

	init();
	//0-based indexing
	int v, e;
	cin >> v >> e;
	graph.resize(v, list<pp>());
	while (e--) {
		int u, v, wt;
		cin >> u >> v >> wt;
		add_edge(u, v, wt);
	}
	int src;
	cin >> src;
	unordered_map<int, int> shortest_path = dijkstra(src, v);
	for (int i = 0; i < v; i++) {
		cout << i << " " << shortest_path[i] << endl;
	}

	return 0;


}