#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		long long h, w, x, y, k;
		cin >> h >> w >> x >> y >> k;
		long long a = pow(abs(w - x), 2);
		long long b = pow(abs(h - y), 2);
		double ans = sqrt(a + b);
		if (ans < k) cout << 1 << endl;
		else cout << 0 << endl;
	}

}