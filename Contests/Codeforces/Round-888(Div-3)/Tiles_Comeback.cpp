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
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int temp = arr[n - 1];
		int idx = -1;
		int cnt = 0;
		bool flag = false;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] == temp) {
				cnt++;
			}
			if (cnt == k) {
				flag = true;
				idx = i;
				break;
			}
		}
		if (flag == false) {
			cout << "NO" << endl;
			continue;
		}
		if (flag == true && idx == 0) {
			cout << "YES" << endl;;
			continue;
		}
		int l = arr[0];
		if (l == arr[n - 1]) {
			cout << "YES" << endl;
			continue;
		}
		int ans = 0;
		for (int i = 0; i <= idx - 1; i++) {
			if (arr[i] == l)
				ans++;
		}
		if (ans >= k) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;
	}

}