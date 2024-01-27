#include<bits/stdc++.h>
using namespace std;

/*
Q : Given an integer array. Find the length of
	longest subarray which has maximum possible
	bitwise AND value.
*/



int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {12, 3, 1, 6, 1, 6, 6, 6, 6, 4, 3, 8, 13, 13, 13, 13, 8};

	int ans = 0;
	int max_el = INT_MIN;
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > max_el) {
			max_el = arr[i];
			count = 1;
		}
		else if (arr[i] == max_el) {
			count++;
		}
		ans = max(ans, count);
	}
	cout << ans;

}