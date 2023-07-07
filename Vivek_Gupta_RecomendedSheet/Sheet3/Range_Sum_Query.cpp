#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int n, t;
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long ans[n];
	ans[0] = arr[0];
	for (int i = 1; i < n; i++) {
		ans[i] = ans[i - 1] + arr[i];
	}

	while (t--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (x == 0) {
			cout << ans[y];
		}
		else cout << ans[y] - ans[x - 1];
		cout << endl;
	}
}