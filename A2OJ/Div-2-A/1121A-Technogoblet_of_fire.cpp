#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init(){

	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> p(n + 1), s(n + 1), a(m + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		a[s[i]] = max(a[s[i]], p[i]);
	}
	int res = 0;
	while (k--) {
		int c;
		cin >> c;
		if (p[c] != a[s[c]]) ++res;
	}
	cout << res << endl;
}

int main() {

	init();


	solve();

}