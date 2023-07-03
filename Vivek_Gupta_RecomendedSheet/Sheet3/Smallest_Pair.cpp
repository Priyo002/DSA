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
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int mini = INT_MAX;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				mini = min(mini, arr[i] + arr[j] + j - i);
			}
		}
		cout << mini << endl;
	}
}