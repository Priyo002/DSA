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
	vector<double> v(n);
	bool flag = true;
	//int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (((int)v[i] & 1) && flag) {
			//sum += floor(v[i] / 2);
			int k1 = floor(v[i] / 2.0);
			cout << k1 << endl;
			flag = false;
		}
		else if (((int)v[i] & 1) && flag == false) {
			//sum += ceil(v[i] / 2);
			int k2 = ceil(v[i] / 2.0);
			cout << k2 << endl;
			flag = true;
		}
		else {
			//sum += (v[i] / 2);
			int k3 = v[i] / 2.0;
			cout << k3 << endl;
		}
	}
	//cout << sum << endl;

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}