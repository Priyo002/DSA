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

// string decode(string& input) {
// 	string res = "";
// 	if (input.size() == 1) {
// 		res += (char)(64 * input[0] - '0');
// 	}
// 	else {
// 		int num = (input[0] - '0') * 10 + (input[1] - '0');
// 		res += (char)(64 + num);
// 	}
// 	return res;
// }

vector<int> dp;

// int f(string &str, int i) {
// 	if (i <= 0) return 1;
// 	if (dp[i] != -1) return dp[i];
// 	int ans = 0;
// 	if (str[i] - '0' > 0) {
// 		ans += f(str, i - 1);
// 	}
// 	if (str[i - 1] - '0' > 0 && (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26 ) {
// 		ans += f(str, i - 2);
// 	}
// 	return dp[i] = ans;
// }

int fbu(string &str) {
	dp.resize(6000, 0);
	dp[0] = 1;
	if (str.size() > 1) {
		if (str[1] != '0') dp[1] += dp[0];
		if ((str[0] - '0') * 10 + (str[1] - '0') <= 26) dp[1]++;
	}
	for (int i = 2; i < str.size(); i++) {
		int ans = 0;
		if (str[i] - '0' > 0) {
			ans += dp[i - 1];
		}
		if (str[i - 1] - '0' > 0 && (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26 ) {
			ans += dp[i - 2];
		}
		dp[i] = ans;
	}
	return dp[str.size() - 1];
}

int32_t main() {

	init();

	string n;
	cin >> n;
	while (n[0] != '0') {
		dp.clear();
		// dp.resize(6000, -1);
		// cout << f(n, n.size() - 1) << endl;
		cout << fbu(n) << endl;
		cin >> n;
	}

}