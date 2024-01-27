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

int v;//No. of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
	graph[src].push_back(dest);
	if (bi_dir) {
		graph[dest].push_back(src);
	}
}

void display() {
	for (int i = 0; i < graph.size(); i++) {
		cout << i << " -> ";
		for (auto el : graph[i]) {
			cout << el << ",";
		}
		cout << endl;
	}
}

bool dfs(int src, int parent, unordered_set<int>& visited) {
	visited.insert(src);
	for (auto neighbour : graph[src]) {
		if (visited.count(neighbour) && neighbour != parent) {
			//cycle detected
			return true;
		}
		if (!visited.count(neighbour)) {
			bool res = dfs(neighbour, src, visited);
			if (res) return true;
		}
	}
	return false;
}

bool has_cycle() {
	unordered_set<int> visited;
	bool result = false;
	for (int i = 0; i < v; i++) {
		if (!visited.count(i)) {
			result = dfs(i, -1, visited);
			if (result) return true;
		}
	}
	return false;
}

int main() {

	init();

	cin >> v;
	graph.resize(v, list<int>());
	int e;
	cin >> e;
	while (e--) {
		int s, d;
		cin >> s >> d;
		add_edge(s, d);
	}
	display();
	bool b = has_cycle();
	cout <<  b << endl;
	return 0;
}