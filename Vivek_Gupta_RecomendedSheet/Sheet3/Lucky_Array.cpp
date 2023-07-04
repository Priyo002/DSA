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
	int mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mini = min(mini, arr[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == mini) cnt++;
	}
	if (cnt % 2 != 0) cout << "Lucky";
	else cout << "Unlucky";

}