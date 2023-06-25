#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int ans = INT_MIN;
	for (int i = 1; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0) ans = max(ans, i);
	}
	cout << ans;
}