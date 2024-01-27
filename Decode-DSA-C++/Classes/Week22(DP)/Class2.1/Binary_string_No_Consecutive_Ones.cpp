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

int n;
void binary(string s) {
	if (s.size() == n) {
		cout << s << endl;
		return;
	}
	binary(s + "0");
	if (s.size() == 0 || s.back() != '1')
		binary(s + "1");
}

int32_t main() {

	init();

	cin >> n;
	binary("");

}