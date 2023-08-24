#include<bits/stdc++.h>
using namespace std;

#define int long long int
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
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (i == 0 || x != a.back())
		{
			a.push_back(x);
		}
	}
	int num_valley = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if ((i == 0 || a[i - 1] > a[i]) && (i == a.size() - 1 || a[i] < a[i + 1]))
		{
			num_valley++;
		}
	}
	if (num_valley == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}