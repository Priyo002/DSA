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
int v;

void add_edge(int a, int b, bool bi_dir = true) {
	graph[a].push_back(b);
	if (bi_dir) {
		graph[b].push_back(a);
	}
}

void topoBFS() {
	//Kahn Algo
	vector<int> indegree(v, 0);
	for (int i = 0; i < v; i++) {
		for (auto neighbour : graph[i]) {
			indegree[neighbour]++;
		}
	}
	queue<int> qu;
	unordered_set<int> visited;
	for (int i = 0; i < v; i++) {
		if (indegree[i] == 0) {
			qu.push(i);
			visited.insert(i);
		}
	}

	while (qu.size()) {
		int node = qu.front();
		cout << node << " ";
		qu.pop();
		for (auto neighbour : graph[node]) {
			if (visited.count(neighbour) == 0) {
				indegree[neighbour]--;
				if (indegree[neighbour] == 0) {
					qu.push(neighbour);
					visited.insert(neighbour);
				}
			}
		}
	}
}

int main() {

	init();

	int e;
	cin >> v >> e;
	graph.resize(v, list<int>());
	while (e--) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y, false);
	}
	topoBFS();


	return 0;
}