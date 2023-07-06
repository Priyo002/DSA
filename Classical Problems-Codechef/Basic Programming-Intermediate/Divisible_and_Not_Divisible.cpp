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
		long long int x, y, z, k;
		cin >> x >> y >> z;
		if (y % z == 0)
			k = -1;
		else {
			k = x + 1;
			if (k % y != 0)
				k += y - (k % y);
			while (k % z == 0)
				k += y;
		}
		cout << k << endl;
	}

}

