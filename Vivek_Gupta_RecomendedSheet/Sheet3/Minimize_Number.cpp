#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] % 2 != 0) {
			cout << 0;
			return 0;
		}
	}
	int cnt = 0;
	while (true) {
		cnt++;
		for (int i = 0; i < n; i++) {
			arr[i] /= 2;
			if (arr[i] % 2 != 0) {
				cout << cnt;
				return 0;
			}
		}
	}
}