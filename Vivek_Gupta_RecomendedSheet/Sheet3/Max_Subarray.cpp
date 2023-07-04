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
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			ans.push_back(arr[i]);
		}

		for (int i = 0; i < n - 1; i++) {
			int maxi = arr[i];
			for (int j = i + 1; j < n; j++) {
				maxi = max(maxi, arr[j]);
				ans.push_back(maxi);
			}
		}
		for (auto ele : ans) {
			cout << ele << " ";
		}
		cout << endl;
	}

}