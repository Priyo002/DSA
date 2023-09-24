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

int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b = (b >> 1);
	}
	return res;
}

void toh(int n, char s, char a, char d) {
	if (n == 0) return;
	toh(n - 1, s, d, a);
	cout << s << " " << d << endl;
	toh(n - 1, a, s, d);
}

void solve() {

}

int32_t main() {

	init();

	int n;
	cin >> n;
	cout << powr(2, n) - 1 << endl;
	toh(n, '1', '2', '3');
}