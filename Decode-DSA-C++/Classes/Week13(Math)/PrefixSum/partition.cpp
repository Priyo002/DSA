#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {1, 2, 3, 4, 5, 5, 10};
	int n = v.size();
	//formation of prefix sum
	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
	}
	//check if any x exists
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (2 * v[i] == v[n - 1]) {
			idx = i;
			break;
		}
	}
	if (idx != -1) cout << "Yes it can be partitioned after " << idx;
	else cout << "No it can't be partitioned";

}