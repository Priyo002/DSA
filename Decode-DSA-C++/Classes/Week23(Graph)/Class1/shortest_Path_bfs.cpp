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

void bfs(int src, vector<int>& dist) {
	queue<int> qu;
	visited.clear();
	dist.resize(v, INT_MAX);
	dist[src] = 0;
	visited.insert(src);
	qu.push(src);
	while (qu.size()) {
		int curr = qu.front();
		qu.pop();
		for (auto neighbour : graph[curr]) {
			if (visited.count(neighbour) == 0) {
				qu.push(neighbour);
				visited.insert(neighbour);
				dist[neighbour] = dist[curr] + 1;
			}
		}
	}
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
		add_edge(s, d, false);
	}
	int x;
	cin >> x;
	vector<int> dist;
	bfs(x, dist);
	for (auto x : dist) cout << x << " ";


	return 0;
}