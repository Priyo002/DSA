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

int dp[2005][2005][8];
int korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
	if (n == i || m == j) return 0;
	if (dp[i][j][k] != -1) return dp[i][j][k];
	int res = 0;
	if (a[i] == b[j]) {
		res = 1 + korderedLCS(a, b, n, m, i + 1, j + 1, k);
	}
	else {
		if (k > 0) {
			res = 1 + korderedLCS(a, b, n, m, i + 1, j + 1, k - 1);
		}
		res = max(res, korderedLCS(a, b, n, m, i + 1, j, k));
		res = max(res, korderedLCS(a, b, n, m, i, j + 1, k));
	}
	return dp[i][j][k] = res;
}

int32_t main() {

	init();
	for (int i = 0; i < 2005; i++) {
		for (int j = 0; j < 2005; j++) {
			for (int l = 0; l < 8; l++) {
				dp[i][j][l] = -1;
			}
		}
	}

	int n, m, k;
	cin >> n >> m >> k;
	int a[n] , b[m];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	cout << korderedLCS(a, b, n, m, 0, 0, k);

}