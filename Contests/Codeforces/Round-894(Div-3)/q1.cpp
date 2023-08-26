#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

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
	int n, m;
	cin >> n >> m;
	char arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	if (m < 4) {
		cout << "NO" << endl;
		return;
	}
	string ans = "";
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 'v' && ans.size() == 0) {
				ans.push_back('v');
				break;
			}
			else if (arr[i][j] == 'i' && ans.back() == 'v') {
				ans.push_back('i');
				break;
			}
			else if (arr[i][j] == 'k' && ans.back() == 'i') {
				ans.push_back('k');
				break;
			}
			else if (arr[i][j] == 'a' && ans.back() == 'k') {
				ans.push_back('a');
				break;
			}
		}
	}
	if (ans == "vika") cout << "YES";
	else cout << "NO";
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}