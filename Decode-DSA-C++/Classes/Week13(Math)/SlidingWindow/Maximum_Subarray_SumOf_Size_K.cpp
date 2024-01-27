#include<bits/stdc++.h>
using namespace std;

//Sliding Window algorithm

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {7, 1, 2, 5, 8, 4, 9, 3, 6};
	int k = 3;
	int n = arr.size();

	int maxIdx = 0;
	int prevSum = 0;
	for (int i = 0; i < k; i++) {
		prevSum += arr[i];
	}
	int maxSum = prevSum;
	int i = 1;
	int j = k;
	while (j < n) {
		int currSum = prevSum + arr[j] - arr[i - 1];
		if (currSum > maxSum) {
			maxSum = currSum;
			maxIdx = i;
		}
		prevSum = currSum;
		i++;
		j++;
	}
	cout << maxSum << endl;
	cout << maxIdx;

}