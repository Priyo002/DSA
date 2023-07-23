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
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		vector<int> v = arr;
		sort(v.begin(), v.end());
		if (v != arr) {
			cout << 0 << endl;
			continue;
		}
		int mini = INT_MAX;
		int idx = -1;
		for (int i = 1; i < n; i++) {
			int k = arr[i] - arr[i - 1];
			if (k < mini) {
				mini = k;
				idx = i;
			}
		}

		int a = arr[idx - 1];
		int b = arr[idx];
		int cnt = 0;
		cout << a << b;
		continue;
		while (a <= b) {
			a++;
			b--;
			cnt++;
		}
		cout << cnt << endl;
	}
}