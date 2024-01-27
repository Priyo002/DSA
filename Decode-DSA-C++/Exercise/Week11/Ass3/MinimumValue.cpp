#include<bits/stdc++.h>
using namespace std;

int mini(int arr[], int n, int idx, int mi) {
	if (idx == n - 2) {
		return mi;
	}
	return mini(arr, n, idx + 1, min(arr[idx], arr[idx + 1]));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {2, 3, 4, 1, 5, 8};
	int n = sizeof(arr) / sizeof(int);
	int ans = mini(arr, n, 0, INT_MAX);
	cout << ans;
}