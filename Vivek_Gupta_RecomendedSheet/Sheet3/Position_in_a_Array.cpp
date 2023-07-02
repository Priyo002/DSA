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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= 10) {
			cout << "A[" << i << "]" << " = " << arr[i] << endl;
		}
	}

}