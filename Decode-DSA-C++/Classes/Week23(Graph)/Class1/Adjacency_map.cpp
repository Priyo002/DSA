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

vector<unordered_map<int, int>> graph;

int v;//No. of vertices
void add_edge(int src, int dest, int wt, bool bi_dir = true) {
	graph[src][dest] = wt;
	if (bi_dir) {
		graph[dest][src] = wt;
	}
}

void display() {
	for (int i = 0; i < graph.size(); i++) {
		cout << i << " -> ";
		for (auto el : graph[i]) {
			cout << "(" << el.first  << "," << el.second << ")" << " , ";
		}
		cout << endl;
	}
}

int main() {

	init();

	cin >> v;
	graph.resize(v, unordered_map<int, int>());
	int e;
	cin >> e;
	while (e--) {
		int s, d, wt;
		cin >> s >> d >> wt;
		add_edge(s, d, wt);
	}
	display();
	return 0;
}