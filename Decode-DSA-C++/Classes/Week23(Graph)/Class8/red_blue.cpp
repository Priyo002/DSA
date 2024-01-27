#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

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
Q : You are given an undirected unweighted graph
with a source & destination. Every edge has a color either red or blue.
Find the shortest path between source & destination such that
	1. The path always starts from a red edges and ends at a blue edge.
	2. You can shift from red edge to blue only once.
	3. There are no self loops or multiple edges.
*/


vector<list<int>> graph;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
	graph[src].push_back(dest);
	if (bi_dir) {
		graph[dest].push_back(src);
	}
}


int32_t main() {

	init();
	int e;
	cin >> v >> e;
	while (e--) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y);
	}
	int src, dest;
	cin >> src >> dest;
	cout << shortest(src, dest);

}