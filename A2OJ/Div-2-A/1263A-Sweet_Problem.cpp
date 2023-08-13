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
	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (v[0] + v[1] >= v[2]) {
		cout << (v[0] + v[1] + v[2]) / 2 << endl;
	}
	else cout << v[0] + v[1] << endl;

}

int main() {

	init();

	ll t;
	cin >> t;
	while (t--)
		solve();

}