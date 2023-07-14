#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << " " << 0 << " " << 1;
		return 0;
	}
	if (n == 0) {
		cout << 0 << " " << 0 << " "  << 0;
		return 0;
	}

	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	while (arr[arr.size() - 1] != n) {
		int t = arr.size();
		int k = arr[t - 1] + arr[t - 2];
		arr.push_back(k);
	}
	int k = arr.size();
	cout << 0 << " " << arr[k - 2] << " " << arr[k - 3];

}