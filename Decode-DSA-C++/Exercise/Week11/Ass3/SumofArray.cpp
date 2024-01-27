#include<bits/stdc++.h>
using namespace std;

int sumofall(int arr[], int n, int idx) {
	if (idx == n - 1) {
		return arr[idx];
	}
	return arr[idx] + sumofall(arr, n, idx + 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int arr[] = {2, 3, 4, 1, 5};
	int n = sizeof(arr) / sizeof(int);
	int ans = sumofall(arr, n, 0);
	cout << ans;
}