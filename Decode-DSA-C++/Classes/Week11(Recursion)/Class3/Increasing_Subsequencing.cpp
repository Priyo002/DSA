#include<bits/stdc++.h>
using namespace std;

void PrintSubset(int arr[], int n, int idx, vector<int> ans, int k) {
	if (idx == n) {
		if (ans.size() == k) {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	if (ans.size() + (n - idx) < k) return;
	PrintSubset(arr, n, idx + 1, ans, k);
	ans.push_back(arr[idx]);
	PrintSubset(arr, n, idx + 1, ans, k);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v;
	int k = 3;
	PrintSubset(arr, n, 0, v, k);


}