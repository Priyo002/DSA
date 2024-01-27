#include<bits/stdc++.h>
using namespace std;

/*
Q : Given an interger array where every element
	occurs twice except one occurs only once.
	Find that unique element.
*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	//	XOR has commutitave property
	// 	Means a^b = b^a

	vector<int> arr = {2, 7, 4, 6, 1, 1, 2, 4, 7};
	int ans = 0;
	for (auto i : arr) {
		ans = ans ^ i;
	}
	cout << ans;

}