#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		int mini = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mini = min(mini, arr[i]);
		}
		int mini2 = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mini && arr[i] < mini2)
				mini2 = arr[i];
		}
		cout << mini2 << endl;
	}
}