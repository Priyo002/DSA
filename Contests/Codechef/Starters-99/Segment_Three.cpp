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
		int n;
		cin >> n;
		vector<long long> arr(n), v(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long ans = 0;
		long long cnt = 0;
		v = arr;
		for (int i = 1; i < 3; i++) {
			v[i] += v[i - 1];
		}
		while (v[2] % 3 != 0) {
			v[2]++;
			cnt++;
		}
		arr[2] += cnt;
		ans += cnt;
		if (n > 3) {
			for (int i = 3; i < n; i++) {
				v[i] += v[i - 1] - arr[i - 3];
				cnt = 0;
				while (v[i] % 3 != 0) {
					v[i]++;
					cnt++;
				}
				arr[i] += cnt;
				ans += cnt;
			}
		}
		cout << ans << endl;

	}

}