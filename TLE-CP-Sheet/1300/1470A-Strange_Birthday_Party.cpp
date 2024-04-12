#include<bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
const int mod = 1e9 + 7;
const long long INF = 1e18;
#define pp pair<int,int>

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
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n), prize(k);

	for (auto&i : arr) cin >> i;
	for (auto&i : prize) cin >> i;

	sort(arr.begin(), arr.end(), [&prize](int &a, int &b) {
		return prize[a - 1] > prize[b - 1];
	});

	priority_queue<pp, vector<pp>, cmp> pq;

	set<int> st;

	for (int i = 0; i < k; i++) {
		st.insert(i);
	}

	vector<bool> visited(k + 1, false);

	int ans = 0;

	for (auto x : arr) {
		int idx = x - 1;

		int costA = prize[idx];
		int costB;

		if ((int)st.size()) {
			auto it = *st.begin();
			costB = prize[it];
			if (costB < costA && it <= idx) {
				st.erase(it);
				ans += costB;
			}
			else {
				ans += costA;
			}
		}
		else {
			ans += costA;
		}


	}

	// for (auto x : arr) cout << x << " ";
	// cout << endl;
	cout << ans << endl;
}


int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}