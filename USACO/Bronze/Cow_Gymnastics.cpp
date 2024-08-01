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



void solve() {
	int k, n;
	cin >> k >> n;
	set<pair<int, int> > cows, used;
	for (int i = 0; i < k; ++i) {
		vector<int> tmp(n);
		for (int j = 0; j < n; ++j) cin >> tmp[j];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int a = tmp[i];
				int b = tmp[j];
				if (cows.count({b, a})) {
					used.insert({b, a});
					cows.erase({b, a});
				}
				if (!used.count({a, b}) && !used.count({b, a})) cows.insert({a, b});
			}
		}
	}
	cout << cows.size() << endl;
}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}