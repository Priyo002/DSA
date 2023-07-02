#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long t, h, x, y;
	cin >> t;
	while (t--) {
		cin >> h >> x >> y;
		if (x > y) cout << 1;
		else cout << 0;
		cout << endl;

	}
	return 0;

}