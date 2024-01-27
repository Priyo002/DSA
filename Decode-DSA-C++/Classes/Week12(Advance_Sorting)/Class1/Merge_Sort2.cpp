#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

int a[] = {5, 1, 2, 4, 3, 53, -1, 0, 10, 100, -3, 103, 1000, 100, 2, -100};
int b[100];


void merge(int lo, int mid, int hi) {

	int k = lo;
	int i = lo;
	int j = mid + 1;

	while (i <= mid && j <= hi) {
		if (a[i] <= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}

	if (i > mid)
		while (j <= hi) b[k++] = a[j++];

	if (j > hi)
		while (i <= mid) b[k++] = a[i++];

	for (int i = lo; i <= hi; i++) a[i] = b[i];
}

void MergeSort(int low, int high) {

	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(low, mid);
		MergeSort(mid + 1, high);
		merge(low, mid, high);
	}

}

int32_t main() {

	init();

	int n = sizeof(a) / sizeof(int);
	MergeSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << a[i] << " ";

}