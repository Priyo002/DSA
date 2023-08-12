#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

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
	vector<int> m;
	vector<int> a;
	int mini = INT_MAX;
	while (n--) {
		int k;
		cin >> k;
		a.clear();
		a.resize(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		m.push_back(a[1]);
		mini = min(mini, a[0]);
	}
	sort(m.begin(), m.end());
	m[0] = mini;
	cout << accumulate(m.begin(), m.end(), 0ll) << endl;
}

int main() {

	init();

	ll t;
	cin >> t;
	while (t--)
		solve();

}