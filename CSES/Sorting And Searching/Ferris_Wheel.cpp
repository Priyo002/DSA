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
	int n, w;
	cin >> n >> w;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr);
	int i = 0;
	int j = n - 1;
	int cnt = 0;
	while (i <= j) {
		if (i == j) {
			cnt++;
			break;
		}
		else if (arr[i] + arr[j] <= w) {
			cnt++;
			i++;
			j--;
		}
		else if (arr[i] + arr[j] > w) {
			cnt++;
			j--;
		}
		else i++;
	}
	cout << cnt;
}

int32_t main() {

	init();


	solve();

}