#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
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
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	unordered_map<int, int> mp;

	int i = 0,  j = 0, ans = 0;

	while (j < n) {
		mp[arr[j]]++;

		while (i < j && (int)(mp.size()) > k) {
			mp[arr[i]]--;
			if (mp[arr[i]] == 0) mp.erase(arr[i]);
			i++;
		}

		ans += (j - i + 1);
		j++;
	}

	cout << ans;
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