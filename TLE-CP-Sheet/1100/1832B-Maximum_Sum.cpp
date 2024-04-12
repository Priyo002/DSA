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

void solve() {
	int n, k;
	cin >> n >> k;


	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr);

	vector<int> temp;

	for (int i = 0; i < n; i++) {
		if ((int)temp.size() == (2 * k)) break;
		temp.push_back(arr[i]);
	}

	int sum = accumulate(temp.begin(), temp.end(), 0ll);


	int ans = sum;

	int j = n - 1;
	int i = temp.size() - 1;

	while (i >= 0) {
		sum -= temp[i];
		i--;
		sum -= temp[i];
		i--;
		sum += arr[j];
		j--;
		ans = min(ans, sum);
	}

	int total = accumulate(arr.begin(), arr.end(), 0ll);

	cout << total - ans << endl;
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