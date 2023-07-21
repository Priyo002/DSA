#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &v, int n) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= n) {
			if (n % v[i] == 0) cnt++;
		}
		else break;
	}
	return cnt;
}

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
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (temp <= n) {
				arr.push_back(temp);
			}
		}
		if (arr.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		sort(arr.begin(), arr.end());
		// for (auto it : arr) {
		// 	cout << it << " ";
		// }
		// cout << endl;
		int maxi = INT_MIN;
		for (int i = arr[0]; i <= n; i++) {
			int l = helper(arr, i);
			maxi = max(maxi, l);
		}
		cout << maxi << endl;
	}

}