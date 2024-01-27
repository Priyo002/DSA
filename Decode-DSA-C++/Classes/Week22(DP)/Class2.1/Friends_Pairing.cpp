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

/* Question :

 * There are n friends wanna go to party each they can go
 * single or paired. In how many ways they can go to the
 * party.
 */

int fact(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++)
		ans *= i;

	return ans;
}

int f(int n) {
	if (n == 1 || n == 2) return n;
	return f(n - 1) + (n - 1) * f(n - 2);
}

int32_t main() {

	init();

	int n;
	cin >> n;
	cout << f(n);

}