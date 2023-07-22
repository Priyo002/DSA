#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(2 * n);
	for (int i = n; i < 2 * n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (auto it : arr) cout << it << " ";

}