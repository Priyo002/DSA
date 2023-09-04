#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
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

void display(vector<int>&arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl;
}

void solve() {
	int n, k, b, s;
	cin >> n >> k >> b >> s;
	vector<int> arr(n, 0);
	if ((s / k) == b) {
		arr[arr.size() - 1] = s;
		display(arr);
		return;
	}
	if (b * k > s) {
		cout << -1 << endl;
		return;
	}
	int prod1 = (n - 1) * (k - 1);
	int prod2 = s - ((b + 1) * k - 1);
	if (prod1 < prod2) {
		cout << -1 << endl;
		return;
	}
	int p = prod2;
	arr[n - 1] = (b + 1) * k - 1;
	int i = n - 2;
	while (i >= 0 && p >= 0) {
		arr[i] = k - 1;
		p -= (k - 1);
		i--;
	}
	for (int i = 0; i <= n - 2 && p < 0; i++) {
		if (arr[i] == 0) continue;
		if (arr[i] + p >= 0) {
			arr[i] += p;
			break;
		}
		else {
			arr[i] = 0;
			p += arr[i];
		}
	}
	display(arr);

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}