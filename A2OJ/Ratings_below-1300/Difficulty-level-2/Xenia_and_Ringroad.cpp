#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	long long sum = 0;
	vector<int> arr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	sum += arr[0] - 1;
	for (int i = 1; i < m; i++) {
		if (arr[i - 1] > arr[i]) {
			sum += ((n - arr[i - 1]) + arr[i]);
		}
		else {
			sum += (arr[i] - arr[i - 1]);
		}
	}
	cout << sum;

}