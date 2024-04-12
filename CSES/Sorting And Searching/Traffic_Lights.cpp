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

class cmp {
public:
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second - a.first < b.second - b.first;
	}
};

#define pp pair<int,int>

void solve() {
	int x, n;
	cin >> x >> n;

	set<int> st;
	st.insert(0);
	st.insert(x);

	set<pp> check;

	priority_queue<pp, vector<pp>, cmp> pq;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		auto it = st.upper_bound(k);
		int hi = *it , lo = *(--it);

		st.insert(k);

		if (check.count({lo, hi}))
			check.erase({lo, hi});

		check.insert({lo, k});
		check.insert({k, hi});

		pq.push({lo, k});
		pq.push({k, hi});

		while (pq.size()) {
			auto curr = pq.top();

			if (check.count(curr)) {
				cout << curr.second - curr.first << " ";
				break;
			}
			else pq.pop();
		}

	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}