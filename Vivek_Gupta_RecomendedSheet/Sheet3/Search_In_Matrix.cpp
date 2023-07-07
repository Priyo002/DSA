#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int arr[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	for (int i = 0; i < n * m; i++) {
		if (arr[i] == k) {
			cout << "will not take number";
			return 0;
		}
	}
	cout << "will take number";
}