#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	int n;
	cin >> n;
	unordered_map<string, int> mp;
	mp["Icosahedron"] = 20;
	mp["Cube"] = 6;
	mp["Tetrahedron"] = 4;
	mp["Dodecahedron"] = 12;
	mp["Octahedron"] = 8;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sum += mp[s];
	}
	cout << sum;
}

int32_t main() {

	init();

	solve();

}