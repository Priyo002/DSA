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

vector<int> arr;
int n, k;

pair<bool, int> f(int sum) {

	int cnt = 1;
	int currSum = 0;
	int mx = 0;

	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		if (currSum > sum) {
			cnt++;
			currSum = arr[i];
		}

		mx = max(mx, currSum);
	}

	bool flag = (cnt <= k);

	return make_pair(flag, mx);
}

void solve() {

	cin >> n >> k;

	arr.resize(n);

	int totalSum = 0, mx = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		totalSum += arr[i];
		mx = max(mx, arr[i]);
	}

	int lo = mx, hi = totalSum;

	int ans = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto temp = f(mid);

		if (temp.first) {
			ans = temp.second;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}