#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		vector<long long> arr(n);
		for (long long i = 0; i < n; i++) cin >> arr[i];

		vector<long long> v = arr;
		sort(v.begin(), v.end());
		if (v != arr) {
			cout << 0 << endl;
			continue;
		}
		long long mini = INT_MAX;
		long long idx = -1;
		for (long long i = 0; i < n - 1; i++) {
			long long k = arr[i + 1] - arr[i];
			if (k < mini) {
				mini = k;
				idx = i;
			}
		}
		long long a = arr[idx];
		long long b = arr[idx + 1];

		cout << (b - a) / 2 + 1 << endl;
	}
}