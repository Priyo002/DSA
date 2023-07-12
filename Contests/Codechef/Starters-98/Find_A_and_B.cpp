#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long t;
	cin >> t;
	while (t--) {
		long long x, y, z;
		cin >> x >> y >> z;
		bool flag = false;
		if ((x * y) % z == 0) {
			cout << x*y << " " << z;
			flag = true;
		}
		else if ((x * z) % y == 0) {
			cout << x*z << " " << y;
			flag = true;
		}
		else if ((y * z) % x == 0) {
			cout << y*z << " " << x;
			flag = true;
		}
		if (flag == false) cout << -1 ;
		cout << endl;

	}

}