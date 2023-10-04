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

void solve() {
	int n;
	cin >> n;
	vector<int> arr(1008, 0);
	while (n--) {
		int s, t, b;
		cin >> s >> t >> b;
		arr[s] += b;
		arr[t] -= b;
	}
	for (int i = 1; i < arr.size(); i++) {
		arr[i] += arr[i - 1];
	}
	cout << *max_element(arr.begin(), arr.end());

}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}