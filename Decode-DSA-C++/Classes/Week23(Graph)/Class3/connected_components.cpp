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

vector<list<int>> graph;
unordered_set<int> visited;
int v;//No. of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
	graph[src].push_back(dest);
	if (bi_dir) {
		graph[dest].push_back(src);
	}
}

void dfs(int node) {
	visited.insert(node);
	for (auto neighbour : graph[node]) {
		if (visited.count(neighbour) == 0) {
			dfs(neighbour);
		}
	}
}

int connected_components() {
	int res = 0;
	for (int i = 0; i < v; i++) {
		// go to every vertex
		// if from a vertex we can initialse a dfs, we got one more cc
		if (visited.count(i) == 0) {
			res++;
			dfs(i);
		}
	}
	return res;
}

int main() {

	init();

	visited.clear();
	graph.clear();
	cin >> v;
	graph.resize(v, list<int>());
	int e;
	cin >> e;
	while (e--) {
		int s, d;
		cin >> s >> d;
		add_edge(s, d);
	}
	cout << connected_components();


	return 0;
}