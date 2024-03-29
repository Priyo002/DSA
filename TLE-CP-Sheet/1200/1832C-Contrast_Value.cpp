#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

void solve() {
	ll n, b, c = 0, state = 0;
	cin >> n;
	vector < ll > v;
	for (ll i = 0 ; i < n ; i++) {
		cin >> b;
		v.push_back(b);
	}
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	for (ll i = 1 ; i < n ; i++) {
		if ((v[i - 1] > v[i]) and state != 1) {
			c++;
			state = 1;
		}
		else if ((v[i - 1] < v[i]) and state != -1) {
			c++;
			state = -1;
		}
	}
	cout << c + 1 << endl;


}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}