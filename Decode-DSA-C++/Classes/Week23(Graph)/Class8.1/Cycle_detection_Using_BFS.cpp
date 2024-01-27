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

bool bfs(int src) {
	unordered_set<int> visited;
	queue<int> qu;
	vector<int> parent(v, -1);
	qu.push(src);
	visited.insert(src);
	while (qu.size()) {
		int curr = qu.front();
		qu.pop();
		for (auto neighbour : graph[curr]) {
			if (visited.count(neighbour) && parent[curr] != neighbour) return true;
			if (!visited.count(neighbour)) {
				visited.insert(neighbour);
				parent[neighbour] = curr;
				qu.push(neighbour);
			}
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
	bool b = bfs(0);
	cout <<  b << endl;
	return 0;
}