#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int ans = INT_MIN;
	while (n--) {
		int k;
		cin >> k;
		ans = max(ans, k);
	}
	cout << ans;

}