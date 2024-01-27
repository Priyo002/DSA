#include<bits/stdc++.h>
using namespace std;

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
#define int long long

vector<list<pp>> graph;

void add_edge(int src, int dest, int wt, bool bi_dir = true) {
	graph[src].push_back({dest, wt});
	if (bi_dir) {
		graph[dest].push_back({src, wt});
	}
}

int prims(int start_node, int vertices) {
	priority_queue<pp, vector<pp>, greater<pp>> pq; //{weight,node}
	unordered_set<int> visited;
	unordered_map<int, int> parent, curr_cost;
	for (int i = 1; i <= vertices; i++) {
		curr_cost[i] = INT_MAX;
	}
	curr_cost[start_node] = 0;
	pq.push({0, start_node});
	int min_cost = 0;
	int total_edges = 0;
	while (pq.size() && total_edges <= vertices - 1) {
		auto curr = pq.top();
		pq.pop();
		if (visited.count(curr.second)) {
			continue;
		}
		visited.insert(curr.second);
		min_cost += curr.first;
		total_edges++;
		for (auto neighbour : graph[curr.second]) {
			if (!visited.count(neighbour.first) && curr_cost[neighbour.first] > neighbour.second) {
				pq.push({neighbour.second, neighbour.first});
				parent[neighbour.first] = curr.second;
				curr_cost[neighbour.first] = neighbour.second;
			}
		}
	}
	return min_cost;
}


int32_t main() {

	init();

	int v, e;
	cin >> v >> e;
	graph.clear();
	graph.resize(v + 1, list<pp>());
	while (e--) {
		int src, dest, weight;
		cin >> src >> dest >> weight;
		add_edge(src, dest, weight);
	}
	int start_node;
	cin >> start_node;
	cout << prims(start_node, v);


}