#include<bits/stdc++.h>
using namespace std;

/*
Q : First negative number in every window of size k
*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {2, -3, 4, 4, -7, -1, 4, -2, 6};
	int n = arr.size();
	int k = 4;
	int prevIdx = 0;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		if (arr[i] < 0) {
			prevIdx = i;
			break;
		}
	}
	ans.push_back(arr[prevIdx]);
	int i = 1;
	int j = k;
	while (j < n) {
		if (prevIdx >= i) ans.push_back(arr[prevIdx]);
		else {
			prevIdx = -1;
			for (int l = i; l <= j; l++) {
				if (arr[l] < 0) {
					prevIdx = l;
					break;
				}
			}
			if (prevIdx != -1)
				ans.push_back(arr[prevIdx]);
			else
				ans.push_back(1);
		}
		i++;
		j++;
	}
	for (auto ele : ans) {
		cout << ele << " ";
	}
}