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
	int n, sum, a;
	cin >> n >> sum;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[i] = {a, i + 1};
	}
	sort(arr);
	int i = 0;
	int j = n - 1;
	while (i < j) {
		int m = arr[i].first + arr[j].first;
		if (m == sum) {
			cout << arr[i].second << " " << arr[j].second;
			return;
		}
		else if (m < sum) i++;
		else j--;
	}
	cout << "IMPOSSIBLE";
}

int32_t main() {

	init();


	solve();

}