#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int arr[n], brr[m];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> brr[i];

	int idx = 0;
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = idx; j < n; j++) {
			if (brr[i] == arr[j]) {
				flag = true;
				idx = j + 1;
				break;
			}
		}
		if (flag == false) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}