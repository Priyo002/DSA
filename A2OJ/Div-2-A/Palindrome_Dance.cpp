#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int lo = 0;
	int hi = n - 1;
	while (lo < hi) {
		if (arr[lo] != arr[hi]) {
			if ((arr[lo] == 0 && arr[hi] == 1) || (arr[lo] == 1 && arr[hi] == 0)) {
				cout << -1;
				return 0;
			}
			else if (arr[lo] == 2) {
				if (arr[hi] == 1) {
					sum += b;
				}
				else if (arr[hi] == 0) {
					sum += a;
				}
			}
			else if (arr[hi] == 2) {
				if (arr[lo] == 1) {
					sum += b;
				}
				else if (arr[lo] == 0) {
					sum += a;
				}
			}
		}
		else {
			if (arr[lo] == 2 && arr[hi] == 2) {
				sum += (2 * min(a, b));
			}
		}
		lo++;
		hi--;
	}
	if ((n % 2 != 0) && arr[n / 2] == 2) {
		sum += min(a, b);
	}
	cout << sum;
}
