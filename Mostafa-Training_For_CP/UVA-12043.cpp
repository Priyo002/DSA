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


vector<int> f(int n) {
	vector<int> temp;

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			temp.push_back(i);

			if (n / i != i) {
				temp.push_back(n / i);
			}
		}
	}

	return temp;
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;

	vector<int> arr;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			arr.push_back(i);
		}
	}

	int sum1 = 0, sum2 = 0;
	for (auto x : arr) {
		vector<int> temp = f(x);
		sum1 += (int)(temp.size());
		sum2 += accumulate(temp.begin(), temp.end(), 0ll);
	}

	cout << sum1 << " " << sum2 << endl;
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