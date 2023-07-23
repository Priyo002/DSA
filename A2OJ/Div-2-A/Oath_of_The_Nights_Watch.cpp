#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int a = arr[0];
	int b = arr[n - 1];
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (arr[i] > a && arr[i] < b) cnt++;
	}
	cout << cnt;
}