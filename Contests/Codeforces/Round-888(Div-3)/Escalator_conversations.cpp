#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		long long n, m, k, h;
		cin >> n >> m >> k >> h;
		vector<long long> arr(n);
		for (long long i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long d = (m - 1) * k;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			long long temp = abs(h - arr[i]);
			if (temp % k == 0 && temp <= d && temp >= k) cnt++;
		}
		cout << cnt << endl;
	}

}