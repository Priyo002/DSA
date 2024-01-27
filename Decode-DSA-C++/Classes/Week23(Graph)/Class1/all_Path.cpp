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
vector<vector<int>> result;
int v;//No. of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
	graph[src].push_back(dest);
	if (bi_dir) {
		graph[dest].push_back(src);
	}
}

void dfs(int curr, int end, vector<int>& path) {
	if (curr == end) {
		path.push_back(curr);
		result.push_back(path);
		path.pop_back();
		return;
	}
	visited.insert(curr); //mark visited
	path.push_back(curr);
	for (auto neighbour : graph[curr]) {
		if (visited.count(neighbour) == 0) {
			dfs(neighbour, end, path);
		}
	}
	path.pop_back();
	visited.erase(curr);
	return;
}

void allPath(int src, int dest) {
	vector<int> v;
	dfs(src, dest, v);
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
	int x, y;
	cin >> x >> y;
	allPath(x, y);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}

	return 0;
}