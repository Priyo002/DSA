#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n, int idx) {
	if (idx == n) return;
	cout << arr[idx] << " ";
	display(arr, n, idx + 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {2, 1, 6, 3, 9, 0, 2, 7};
	int n = sizeof(arr) / sizeof(int);
	display(arr, n, 0);

}