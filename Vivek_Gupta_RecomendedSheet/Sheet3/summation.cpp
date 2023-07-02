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
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	cout << abs(sum);

}