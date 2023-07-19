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
		vector<long long> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		for (int i = 1; i < n; i++) {
			arr[i] += arr[i - 1];
		}
		cout << arr[n - 1] << " ";
		for (int i = 0; i < n - 1; i++) {
			cout << arr[n - 1] - arr[i] << " ";
		}
		cout << endl;
	}
}