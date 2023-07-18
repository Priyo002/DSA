#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(12);
	for (int i = 0; i < 12; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int cnt = 0;
	int sum = 0;
	if (n == 0) {
		cout << cnt;
		return 0;
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		sum += arr[i];
		cnt++;
		if (sum >= n) {
			cout << cnt;
			return 0;
		}

	}
	cout << -1;

}