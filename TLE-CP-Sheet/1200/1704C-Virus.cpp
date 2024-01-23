#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end())
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
	int n, k;
	cin >> n >> k;


	vector<int> arr(k);
	for (int i = 0; i < k; i++) cin >> arr[i];


	sort(arr.begin(), arr.end());
	vector<int> diff;
	for (int i = 0; i < k - 1; i++) {
		diff.push_back(arr[i + 1] - arr[i] - 1);
	}
	diff.push_back(arr[0] + n - arr[k - 1] - 1);

	int day = 0;
	int safe = 0;

	sort(diff.begin(), diff.end(), greater<int>());

	for (int i = 0; i < diff.size(); i++) {
		int curr = diff[i];
		curr -= (day * 2);
		if (curr <= 0) break;
		safe += (curr - 1);
		if (curr == 1) safe++;
		day += 2;
	}
	cout << n - safe << endl;
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