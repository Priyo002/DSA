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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		int maxi = INT_MIN;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] <= 10 && b[i] > maxi) {
				maxi = b[i];
				idx = i;
			}
		}
		cout << idx + 1 << endl;

	}

}