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

vector<bool> visited;
unordered_set<int> st;
int n, k;

void dsu(int i) {

	if (i >= n || i < 0 || visited[i]) return;

	visited[i] = true;
	st.insert(i);

	dsu(i + k);
	dsu(i + k + 1);
	dsu(i - k);
	dsu(i - k - 1);
}

void solve() {
	cin >> n >> k;
	string s, t;
	cin >> s >> t;

	visited.clear();
	st.clear();

	visited.resize(n, false);

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		st.clear();
		dsu(i);

		string a = "", b = "";
		for (auto idx : st) {
			a += s[idx];
			b += t[idx];
		}

		sort(a), sort(b);

		if (a != b) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}