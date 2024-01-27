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

vector<vector<int>> dp;
string s1, s2, ans = "";
int f(string &s1, string &s2, int i, int j, string output) {
	if (ans.size() < output.size()) ans = output;
	if (i >= s1.size()) return 0;
	if (j >= s2.size()) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + f(s1, s2, i + 1, j + 1, output + s1[i]);
	}
	else {
		return dp[i][j] = max(f(s1, s2, i + 1, j, output), f(s1, s2, i, j + 1, output));
	}
}

signed main() {

	init();
	dp.clear();
	dp.resize(1005, vector<int>(1005, -1));
	cin >> s1 >> s2;
	int n = f(s1, s2, 0, 0, "");
	cout << ans;
	return 0;

}