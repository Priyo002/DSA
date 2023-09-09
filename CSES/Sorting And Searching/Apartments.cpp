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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n), b(m);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(arr);
	sort(b);
	int i = 0;
	int j = 0;
	int cnt = 0;
	while (i < n && j < m) {
		if (b[j] <= arr[i] + k && b[j] >= arr[i] - k) {
			cnt++;
			i++;
			j++;
		}
		else if (arr[i] > b[j]) j++;
		else i++;
	}
	cout << cnt;
}

int32_t main() {

	init();


	solve();

}