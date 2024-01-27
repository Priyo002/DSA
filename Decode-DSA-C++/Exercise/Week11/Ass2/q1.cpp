#include<bits/stdc++.h>
using namespace std;

void rev(int arr[], int n) {
	if (n < 0) return;
	cout << arr[n] << " ";
	rev(arr, n - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(n);
	rev(arr, n - 1);
}