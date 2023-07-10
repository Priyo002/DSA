#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	int x = 0;
	int maxi = INT_MIN;
	while (t--) {
		int a, b;
		cin >> a >> b;
		x -= a;
		x += b;
		maxi = max(maxi, x);
	}
	cout << maxi;

}