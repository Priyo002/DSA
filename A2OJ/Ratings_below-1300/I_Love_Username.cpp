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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxi = arr[0], mini = arr[0];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxi) {
			maxi = arr[i];
			cnt++;
		}
		else if (arr[i] < mini) {
			mini = arr[i];
			cnt++;
		}
	}
	cout << cnt;
}