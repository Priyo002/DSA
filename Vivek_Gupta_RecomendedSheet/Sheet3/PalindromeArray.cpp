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

	int lo = 0;
	int hi = n - 1;
	while (lo < hi) {
		if (arr[lo] != arr[hi]) {
			cout << "NO";
			return 0;
		}
		lo++;
		hi--;
	}
	cout << "YES";

}