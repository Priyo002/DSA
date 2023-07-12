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
		vector<int> a(n), d(n);
		int maxi = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			maxi = max(maxi, a[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			maxi = max(maxi, d[i]);
		}

		vector<int> ans(maxi + 1, 0);
		for (int i = 0; i < n; i++) {
			ans[a[i]]++;
			ans[d[i]]++;
		}
		cout << *max_element(ans.begin(), ans.end()) << endl;
	}
}