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

void quickSort(int arr[], int si, int ei) {
	if (si >= ei) {
		return;
	}
	int pivotIndex = partition(arr, si, ei);

	quickSort(arr, si, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, ei);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
	int n = sizeof(arr) / sizeof(int);
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
	quickSort(arr, 0, n - 1);
	for (auto i : arr) {
		cout << i << " ";
	}

}