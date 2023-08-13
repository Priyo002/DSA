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
	vector<int> v(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]] = i;
	}
	int k = n;
	for (int i = 0; i < n; i++) {
		if (v[i] != k) {
			cout << endl;
		}
		else {
			cout << v[i] << " ";
			k--;
			while (k > 0 && mp[k] < i) {
				cout << k << " ";
				k--;
			}
			if (k != 0)
				cout << endl;
		}
	}

}

int main() {

	init();

	solve();

}