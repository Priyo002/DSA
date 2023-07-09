#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n % 2 != 0) {
		cout << -1;
		return 0;
	}
	else {
		int arr[n + 1];
		vector<int> ans(n);

		int k = 0;
		int cnt = 2;
		while (k < n) {
			ans[k++] = cnt;
			cnt--;
			ans[k++] = cnt;
			cnt += 3;
		}
		for (auto ele : ans) {
			cout << ele << " ";
		}
	}
}