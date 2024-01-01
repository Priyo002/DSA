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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = -1, end = -1;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1] && start == -1) {
			start = i;
			//cout << start << " he ";
		}
		if (arr[i] < arr[i + 1] && start != -1) {
			//cout << arr[i] << " " << arr[i + 1] << " " << start << " ";
			end = i;
			//cout << end << endl;
			break;
		}
	}
	if (start == -1 && end == -1) {
		cout << "yes" << endl;
		cout << 1 << " " << 1 << endl;
		return ;
	}
	if (end == -1 && start != -1) {
		end = n - 1;
	}
	reverse(arr.begin() + start, arr.begin() + end + 1);
	if (is_sorted(arr.begin(), arr.end())) {
		cout << "yes" << endl;
		cout << start + 1 << " " << end + 1 << endl;
	}
	else cout << "no" << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	// int t;
	// cin >> t;
	// while (t--)
	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}