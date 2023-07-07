#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	while (t--) {
		int i;
		cin >> i;
		if (binary_search(arr.begin(), arr.end(), i))
			cout << "found";
		else cout << "not found";
		cout << endl;
	}

}