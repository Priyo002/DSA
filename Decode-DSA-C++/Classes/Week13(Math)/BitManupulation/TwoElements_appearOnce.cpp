#include<bits/stdc++.h>
using namespace std;

/*
Q : Given an integer array nums, in which exactly
	two elements appeat only once and all the other
	elements appear exactly twice. Find the two elements
	that appear only once.
*/

void find_Unique(vector<int> &v) {
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res ^= v[i];
	}
	int temp = res;
	int k = 0;
	while (true) {
		if ((temp & 1) == 1) {
			break;
		}
		temp = temp >> 1;
		k++;
	}
	int val = 0;
	for (int i = 0; i < v.size(); i++) {
		int num = v[i];
		if ((num >> k) & 1 == 1) val ^= num;
	}

	cout << val << " ";//First Number
	res = res ^ val;
	cout << res;//Second Number
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {1, 2, 1, 7, 3, 2, 5, 5};
	find_Unique(arr);
}