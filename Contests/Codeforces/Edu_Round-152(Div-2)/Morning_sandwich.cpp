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
		int b, c, h;
		cin >> b >> c >> h;
		int k = c + h;
		if (b - 1 <= k - 1) {
			cout << b + (b - 1) << endl;
		}
		else {
			cout << 2 * k + 1 << endl;
		}
	}

}