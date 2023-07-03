#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		long long n, cost;
		cin  >> n >> cost;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		bool flag = true;
		long long totalcost = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 1) totalcost += cost;
			else if (i == 0 && arr[i] == 0) totalcost += 0;
			else if (i != 0 && arr[i] == 0 && arr[i - 1] == 1) totalcost += cost;
		}
		cout << totalcost << endl;

	}
}