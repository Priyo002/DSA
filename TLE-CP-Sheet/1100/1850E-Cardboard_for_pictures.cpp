#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
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
int n, c;
vector<int> arr;

int f(int x) {

	int sum = 0;
	for (auto y : arr) {
		sum += ((2ll * x + y) * (2ll * x + y));
		if (sum > c) break;
	}

	return sum;
}

void solve() {
	cin >> n >> c;

	arr.clear();
	arr.resize(n);



	for (int i = 0; i < n; i++) {
		cin >> arr[i];


	}

	int lo = 1, hi = (int)1e9;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2ll;

		int k = f(mid);

		if (k == c) {
			cout << mid << endl;
			return;
		}
		else if (k > c) {
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << 0 << endl;

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}