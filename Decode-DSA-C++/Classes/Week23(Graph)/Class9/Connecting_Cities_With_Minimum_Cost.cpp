#include<bits/stdc++.h>
using namespace std;


//https://www.lintcode.com/problem/3672/

struct edge {
	int src, dest, cost;
};
bool cmp(edge e1, edge e2) {
	return e1.cost < e2.cost;
}
class Solution {
public:

	int find(vector<int>& parent, int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent, parent[x]);
	}
	void Union(vector<int>&parent, vector<int>&rank, int a, int b) {
		a = find(parent, a);
		b = find(parent, b);
		if (a == b) return;
		if (rank[a] >= rank[b]) {
			parent[b] = a;
			rank[a]++;
		}
		else {
			parent[a] = b;
			rank[b]++;
		}
	}
	int kruskal(vector<edge>& arr, int n) {
		sort(arr.begin(), arr.end(), cmp);//O(ElogE)
		vector<int> parent(n + 1), rank(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
		int edgecount = 0;
		int ans = 0;
		int i = 0;
		while (edgecount <= n - 1 && i < arr.size()) {
			edge curr = arr[i];
			int srcpar = find(parent, curr.src);
			int destpar = find(parent, curr.dest);
			if (srcpar != destpar) {
				Union(parent, rank, srcpar, destpar);
				edgecount++;
				ans += curr.cost;
			}
			i++;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == i) cnt++;
		}
		if (cnt > 1) return -1;
		return ans;
	}

	int minimumCost(int n, vector<vector<int>> &connections) {
		// write your code here
		int k = connections.size();
		vector<edge> arr(k);
		for (int i = 0; i < connections.size(); i++) {
			int s = connections[i][0];
			int d = connections[i][1];
			int c = connections[i][2];
			arr[i].src = s;
			arr[i].dest = d;
			arr[i].cost = c;
		}
		return kruskal(arr, n);
	}
};