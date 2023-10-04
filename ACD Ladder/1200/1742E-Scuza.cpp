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
	int n, q;
	cin >> n >> q;
	vector<long long> pref;
	pref.push_back(0);
	vector<int> prefmax;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pref.push_back(pref.back() + x);
		if (i == 0)
		{
			prefmax.push_back(x);
		}
		else
		{
			prefmax.push_back(max(prefmax.back(), x));
		}
	}
	for (int i = 0; i < q; i++)
	{
		int k;
		cin >> k;
		int ind = upper_bound(prefmax.begin(), prefmax.end(), k) - prefmax.begin();
		cout << pref[ind] << " ";
	}
	cout << endl;
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