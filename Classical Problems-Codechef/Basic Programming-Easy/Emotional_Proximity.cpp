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
		int x, y, z;
		double p, ans;
		cin >> p >> x >> y >> z;


		if (z == 1) {
			ans = p + (p * y / 100);
		} else {
			ans = p - (p * x / 100);
		}

		cout << fixed << setprecision(10) << ans << endl;
	}


}