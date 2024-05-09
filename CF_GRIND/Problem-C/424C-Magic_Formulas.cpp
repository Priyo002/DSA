#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
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

int f(int x) {
	int ans = 0;
	if (x % 4 == 0) ans ^= x;
	else if (x % 4 == 1) ans ^= 1;
	else if (x % 4 == 2) ans ^= (x + 1);
	else ans ^= 0;

	return ans;
}


void solve() {
	int n;
	cin >> n;


	vector<int> arr(n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans ^= arr[i];
	}

	for (int i = 1; i <= n; i++) {

		int blocks = n / i;
		if (blocks & 1) ans ^= f(i - 1);

		int leftOver = n % i;
		ans ^= f(leftOver);
	}

	cout << ans;

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	//cin >> _t;
	while (_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}