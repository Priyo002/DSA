#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int mini = INT_MAX;
	int maxi = INT_MIN;
	int maidx = -1, miidx = -1;
	for (int i = 0; i < n; i++) {
		if (mini > arr[i]) {
			mini = arr[i];
			miidx = i;
		}
		if (maxi < arr[i]) {
			maxi = arr[i];
			maidx = i;
		}
	}
	swap(arr[miidx], arr[maidx]);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}