#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int si, int ei) {
	int pivot = arr[(si + ei) / 2];
	int cnt = 0;
	for (int i = si ; i <= ei; i++) {
		if (i == (si + ei) / 2) continue;
		if (arr[i] <= pivot) cnt++;
	}
	int pivotIdx = cnt + si;
	swap(arr[(si + ei) / 2], arr[pivotIdx]);
	int i = si;
	int j = ei;
	while (i < pivotIdx && j > pivotIdx) {
		if (arr[i] > pivot && arr[j] <= pivot) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else if (arr[i] <= pivot) {
			i++;
		}
		else if (arr[j] > pivot)
			j--;
	}
	return pivotIdx;
}

int kthSmallest(int arr[], int si, int ei, int k) {

	int pivotIndex = partition(arr, si, ei);

	if (pivotIndex + 1 == k) return arr[pivotIndex];
	else if (pivotIndex + 1 > k )
		return kthSmallest(arr, si, pivotIndex - 1, k);
	else
		return kthSmallest(arr, pivotIndex + 1, ei, k);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {5, 9, 0, 12, 17, 18};
	int n = sizeof(arr) / sizeof(int);
	for (auto i : arr) {
		cout << i << " ";
	}
	int k = 3;
	cout << endl;
	cout << kthSmallest(arr, 0, n - 1, k) << endl;
}