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
	int minidx = -1;
	int maxidx = -1;
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= mini) {
			mini = arr[i];
			minidx = i;
		}
		if (arr[i] > maxi) {
			maxi = arr[i];
			maxidx = i;
		}
	}
	int ans ;
	if (maxidx > minidx)
		ans = maxidx - 1 + (n - 1) - minidx;
	else
		ans = maxidx + (n - 1) - minidx;
	cout << ans;

}