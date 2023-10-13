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
	int a, b, c;
	cin >> a >> b >> c;
	multiset<int> mt;
	mt.insert(a), mt.insert(b), mt.insert(c);
	for (int i = 0; i < 3 && *mt.begin() != *mt.rbegin(); i++) {
		int x = *mt.rbegin();
		mt.erase(--mt.end());
		mt.insert(*mt.begin());
		mt.insert(x - *mt.begin());
	}
	if (*mt.begin() == *mt.rbegin()) cout << "YES" << endl;
	else cout << "NO" << endl;
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