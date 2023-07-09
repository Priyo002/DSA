#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n][3];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		if (sum >= 2) cnt++;
	}
	cout << cnt;

}