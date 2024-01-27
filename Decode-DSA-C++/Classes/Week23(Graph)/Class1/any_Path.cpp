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

bool dfs(int curr, int end) {
	if (curr == end) return true;
	visited.insert(curr); //mark visited
	for (auto neighbour : graph[curr]) {
		if (visited.count(neighbour) == 0) {
			bool result = dfs(neighbour, end);
			if (result) return true;
		}
	}
	return false;
}

bool anyPath(int src, int dest) {
	return dfs(src, dest);
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
	int x, y;
	cin >> x >> y;
	cout << anyPath(x, y) << endl;


	return 0;
}