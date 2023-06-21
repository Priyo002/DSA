#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> ans(3);
	for (int i = 0; i < 3; i++) {
		cin >> ans[i];
	}
	int mini = *min_element(ans.begin(), ans.end());
	int maxi = *max_element(ans.begin(), ans.end());
	cout << mini << " " << maxi;
}