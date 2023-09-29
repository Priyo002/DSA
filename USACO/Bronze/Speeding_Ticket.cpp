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
	int n, m, s;
	cin >> n >> m;
	vector<int> arr(102, 0), brr(102, 0);
	int r, l;
	cin >> l >> s;
	arr[1] += s;
	arr[l + 1] -= s;
	for (int i = 1; i < n; i++) {
		int k;
		cin >> k >> s;
		r = l + 1;
		l += k;
		arr[r] += s;
		arr[l + 1] -= s;
	}
	cin >> l >> s;
	brr[1] += s;
	brr[l + 1] -= s;
	for (int i = 1; i < n; i++) {
		int k;
		cin >> k >> s;
		r = l + 1;
		l += k;
		brr[r] += s;
		brr[l + 1] -= s;
	}
	for (int i = 1; i <= 100; i++) {
		arr[i] += arr[i - 1];
		brr[i] += brr[i - 1];
		//cout << i <<  " " << brr[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		//cout << i << " " << arr[i] << " " << brr[i] << endl;
		if (brr[i] >= arr[i])
			ans = max(ans, brr[i] - arr[i]);
	}
	cout << ans;
}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}