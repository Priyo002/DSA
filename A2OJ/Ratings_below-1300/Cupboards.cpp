#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	int lz = 0, lo = 0, ro = 0, rz = 0;
	while (t--) {
		int a, b;
		cin >> a  >> b;
		if (a == 0) {
			lz += 1;
		}
		else if (a == 1) lo += 1;
		if (b == 0) rz += 1;
		else if (b == 1) ro += 1;
	}
	cout << min(lo, lz) + min(ro, rz);

}