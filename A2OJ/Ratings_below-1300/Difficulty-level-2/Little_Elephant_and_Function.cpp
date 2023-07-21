#include<bits/stdc++.h>
using namespace std;

void f(vector<int>& arr, int x) {
	if (x == 1) {
		swap(arr[x], arr[x - 1]);
		return;
	}
	swap(arr[x], arr[x - 1]);
	f(arr, x - 1);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << n << " ";
	for (int i = 1; i < n; i++) {
		cout << i << " ";
	}

}