#include<bits/stdc++.h>
using namespace std;

void PrintSubset(int arr[], int n, int idx, vector<int> ans) {
	if (idx == n) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	PrintSubset(arr, n, idx + 1, ans);
	ans.push_back(arr[idx]);
	PrintSubset(arr, n, idx + 1, ans);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v;
	PrintSubset(arr, n, 0, v);


}