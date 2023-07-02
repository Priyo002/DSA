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
	int idx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < mini) {
			idx = i;
			mini = arr[i];
		}
	}
	cout << mini << " " << idx + 1;
}