#include<bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/kruskalmstrsub/problem#!

#define ll long long int

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

int find(vector<int>&parent, int x) {
	//This method returns which group/cluster x belongs to
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	if (a == b) return;//cycle detected
	if (rank[a] >= rank[b]) {
		rank[a]++;
		parent[b] = a;
	}
	else {
		rank[b]++;
		parent[a] = b;
	}
}

struct Edge {
	int src;
	int dest;
	int wt;
};

bool cmp(Edge e1, Edge e2) {
	return e1.wt < e2.wt;
}

ll kruskals(vector<Edge>& input, int n, int e) {//O(V+ElogE)

	sort(input.begin(), input.end(), cmp);//O(ElogE)
	vector<int> parent(n + 1), rank(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int edgeCount = 0;//n-1 (for tree)
	int i = 0;
	ll ans = 0;
	while (edgeCount <= n - 1 && i < input.size()) {//O(Vlog*V)
		Edge curr = input[i];//because input is sorted so we get min wt edge
		int srcPar = find(parent, curr.src);
		int destPar = find(parent, curr.dest);
		if (srcPar != destPar) {
			Union(parent, rank, srcPar, destPar);
			ans += curr.wt;
			edgeCount++;
		}
		i++;
	}
	return ans;
}

int main() {

	init();

	int n, e;
	cin >> n >> e;//n->vertices, e->edges
	vector<Edge> v(e);
	for (int i = 0; i < e; i++) {
		cin >> v[i].src >> v[i].dest >> v[i].wt;
	}

	cout << kruskals(v, n, e) << endl;


	return 0;
}