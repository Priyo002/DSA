#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr(4);
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int cnt = 1;
	int maxi = INT_MIN;
	for (int i = 1; i < 4; i++) {
		if (arr[i] != arr[i - 1]) cnt++;
	}
	cout << 4 - cnt;

}