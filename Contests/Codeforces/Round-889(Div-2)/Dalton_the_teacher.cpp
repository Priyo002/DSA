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
		int cnt  = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == i + 1) {
				cnt++;
			}
		}
		if (cnt % 2 == 0) {
			cout << cnt / 2 << endl;
		}
		else cout << cnt / 2 + 1 << endl;
	}

}