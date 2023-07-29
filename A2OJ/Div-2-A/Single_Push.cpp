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
		vector<int > a(n), b(n);
		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (b[i] != a[i] && idx1 == -1) {
				idx1 = i;
			}
			if (b[i] != a[i]) idx2 = i;
		}
		if (idx1 == -1) {
			cout << "YES" << endl;
			continue;
		}
		int k = b[idx1] - a[idx1];
		if (k < 0) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = idx1; i <= idx2; i++) {
			a[i] += k;
		}
		bool ans = (a == b) ? true : false;
		if (ans == true) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;

	}

}