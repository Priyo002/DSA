#include<bits/stdc++.h>
using namespace std;

#define int long long int
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

vector<int> get_digits(int n) {
	vector<int> res;
	while (n) {
		if (n % 10)
			res.pb(n % 10);
		n /= 10;
	}
	return res;
}
vector<int> dp;

//Top-Down Approach
int f(int n) {
	if (n == 0) return 0;
	if (n <= 9) return 1;
	if (dp[n] != -1) return dp[n];
	vector<int> v = get_digits(n);

	int result = INT_MAX;
	for (int i = 0; i < v.size(); i++) {
		result = min(result, f(n - v[i]));
	}
	return dp[n] = 1 + result;
}

//Bottom-Up Approach
int fbu(int num) {
	dp[0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[i] = 1;
	}
	for (int n = 10; n <= num; n++) {
		//n->state
		//calculate dp[n]
		vector<int> d = get_digits(n);
		int result = INT_MAX;
		for (int i = 0; i < d.size(); i++) {
			result = min(result, dp[n - d[i]]);
		}
		dp[n] = 1 + result;
	}
	return dp[num];
}

int32_t main() {

	init();
	int n;
	cin >> n;
	dp.resize(n + 1, -1);
	//cout << f(n);
	cout << fbu(n);


}