#include<bits/stdc++.h>
using namespace std;

void printMax(int arr[], int n, int idx, int max) {
	if (idx == n) {
		cout << max;
		return;
	}
	if (max < arr[idx]) max = arr[idx];
	printMax(arr, n, idx + 1, max);
}

int printMax2(int arr[], int n, int idx) {
	if (idx == n) return INT_MIN;
	return max(arr[idx], printMax2(arr, n, idx + 1));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {2, 1, 6, 3, 9, 0, 12, 7};
	int n = sizeof(arr) / sizeof(int);
	printMax(arr, n, 0, INT_MIN);
	cout << endl;
	cout << printMax2(arr, n, 0);
}