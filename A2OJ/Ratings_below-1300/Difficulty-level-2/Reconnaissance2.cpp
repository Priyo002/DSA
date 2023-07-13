#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	arr[0] = arr[n];
	arr[arr.size() - 1] = arr[1];
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int a = abs(arr[i] - arr[i + 1]);
		int b = abs(arr[i] - arr[i - 1]);
		ans.push_back(min(a, b));
	}
	int mini = INT_MAX;
	int idx = -1;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] < mini) {
			mini = ans[i];
			idx = i + 1;
		}
	}

	int t = abs(arr[idx] - arr[idx - 1]);
	int t1 = abs(arr[idx] - arr[idx + 1]);
	if (t == mini) {
		if (idx != 1) {
			cout << idx << " " << idx - 1;
		}
		else if (idx == 1) {
			cout << idx << " " << n;
		}
	}
	else {
		if (idx != n) {
			cout << idx << " " << idx + 1;
		}
		else if (idx == n) {
			cout << idx  << " " << 1;
		}
	}
}