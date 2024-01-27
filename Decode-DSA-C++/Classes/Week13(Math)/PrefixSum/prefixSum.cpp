#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {1, 4, 5, 3, 2, 7, 6};
	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		nums[i] = nums[i] + nums[i - 1];
	}
	for (auto i : v) {
		cout << i << " ";
	}
}