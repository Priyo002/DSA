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
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int val = 1;
		for (int i = 1, x = 1; i < n; i++) {
			if (a[i] - a[i - 1] <= k) x++;
			else x = 1;
			val = max(val, x);
		}
		cout << n - val << endl;
	}


}
