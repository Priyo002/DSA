#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> arr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int ans = INT_MAX;
	int i = 0;
	int j = n - 1;
	while (j < m) {
		ans = min(ans, arr[j] - arr[i]);
		i++;
		j++;
	}

	cout << ans;
}