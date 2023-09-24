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

bool f(int i, vector<int>& arr, int sum) {
	if (i == arr.size() && sum % 360 == 0) return true;
	if (i == arr.size() && sum != 0) return false;

	return f(i + 1, arr, sum + arr[i]) || f(i + 1, arr, sum - arr[i]);
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int s = 0;
	if (f(0, arr, s)) cout << "YES";
	else cout << "NO";
}

int32_t main() {

	init();

	solve();

}