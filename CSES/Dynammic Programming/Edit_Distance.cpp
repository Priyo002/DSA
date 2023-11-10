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

string s1, s2;
int dp[5005][5005];
int f(int i, int j) {
	if (i == s1.size()) return s2.size() - j;
	if (j == s2.size()) return s1.size() - i;
	if (dp[i][j] != -1) return dp[i][j];
	int ans = INT_MAX;
	if (s1[i] == s2[j]) {
		ans = min(ans, f(i + 1, j + 1));
	}
	else {
		ans = min(ans, 1 + f(i, j + 1)); //add
		ans = min(ans, 1 + f(i + 1, j)); //remove
		ans = min(ans, 1 + f(i + 1, j + 1)); //replace
	}
	return dp[i][j] = ans;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	cin >> s1 >> s2;
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0);

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}