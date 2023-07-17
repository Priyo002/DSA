#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long x, y, z, mn;
	cin >> x >> y >> z;

	mn = min(x, min(y, z));
	x = x - mn;
	z = z - mn;

	if (x / 2 >= z)
		cout << z + mn << endl;
	else
		cout << x / 2 + mn << endl;
	return 0;

}
