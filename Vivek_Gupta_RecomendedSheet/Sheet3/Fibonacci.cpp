#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n == 1) cout << 0;
	else if (n == 2) cout << 1;
	else {
		vector<long long> arr(n);
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[n - 1];
	}

}