#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int>arr(n);
	int mini = INT_MAX;
	int cnt = 0, idx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (mini > arr[i]) {
			mini = arr[i];
			idx = i;
			cnt = 0;
		}
		else if (mini == arr[i]) {
			cnt++;
		}
	}
	if (cnt) cout << "Still Rozdil";
	else cout << idx + 1;


}