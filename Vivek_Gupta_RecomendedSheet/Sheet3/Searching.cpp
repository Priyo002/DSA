#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	int target;
	cin >> target;

	for (int i = 0; i < n; i++) {
		if (target == arr[i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;

}