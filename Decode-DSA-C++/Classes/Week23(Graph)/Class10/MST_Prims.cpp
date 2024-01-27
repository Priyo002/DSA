#include<bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/primsmstsub/problem

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
1. DS- Visited set, priority_queue<pair<weight,vertex>>, unordered_map
2. insert the pair of <-1,src> in the priority queue
3. if the root element is already visited, then we will just continue
4. we mark the root visited
5. we store the weight of the pair in the ans
6. update the mapping
7. go to every neighbour of the curr element, and only add those which are non visited
and have a better weight proposition.
*/


#define int long long
#define pp pair<int,int>

vector<list<pp>> graph;
void add_edge(int u, int v, int wt, bool bi_dir = true) {
	graph[u].push_back({v, wt});
	if (bi_dir) {
		graph[v].push_back({u, wt});
	}
}

int prims(int src, int n) {//O(VlogV+ElogV+V)
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	unordered_set<int> visited;
	vector<int> parent(n + 1);
	unordered_map<int, int> mp;
	for (int i = 1; i <= n; i++) mp[i] = INT_MAX;
	pq.push({0, src});
	mp[src] = 0;

	int total_count = 0;
	int result = 0;
	while (pq.size() && total_count < n) {
		pp curr = pq.top();
		if (visited.count(curr.second)) {
			pq.pop();
			continue;
		}
		visited.insert(curr.second);
		total_count++;
		result += curr.first;
		pq.pop();
		for (auto neighbour : graph[curr.second]) {
			if (!visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second) {
				pq.push({neighbour.second, neighbour.first});
				parent[neighbour.first] = curr.second;
				mp[neighbour.first] = neighbour.second;
			}
		}
	}
	return result;
}

int32_t main() {

	init();
	//1-based indexing
	int n, m;
	cin >> n >> m;
	graph.resize(n + 1, list<pp>());
	while (m--) {
		int u, v, wt;
		cin >> u >> v >> wt;
		add_edge(u, v, wt);
	}
	int src;
	cin >> src;
	cout << prims(src, n);

	return 0;


}