#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;

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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] <= 0 && a[i + 1] <= 0) {
			a[i] = -a[i];
			a[i + 1] = -a[i + 1];
		}
		else if (a[i] < 0 && a[i + 1] > 0) {
			int k = -a[i];
			if (k > a[i + 1]) {
				a[i] = -a[i];
				a[i + 1] = -a[i + 1];
			}
		}
	}
	cout << accumulate(a.begin(), a.end(), 0ll) << endl;
}

int main() {

	init();

	ll t;
	cin >> t;
	while (t--)
		solve();

}