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
	int n, target;
	cin >> n >> target;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	sort(arr);

	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i].first == arr[i - 1].first) continue;
		for (int j = i + 1; j < n; j++) {
			if (j != i + 1 && arr[j].first == arr[j - 1].first) continue;
			int k = j + 1;
			int l = n - 1;
			while (k < l) {
				int sum = arr[i].first;
				sum += arr[j].first;
				sum += arr[k].first;
				sum += arr[l].first;

				if (sum > target) {
					l--;
				}
				else if (sum < target) {
					k++;
				}
				else {
					cout << arr[i].second << " ";
					cout << arr[j].second << " ";
					cout << arr[k].second << " ";
					cout << arr[l].second ;
					return;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
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