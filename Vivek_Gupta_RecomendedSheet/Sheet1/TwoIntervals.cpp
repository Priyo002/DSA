#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;

	if (min(r1, r2) < max(l1, l2)) cout << -1;
	else if (r1 >= l2) {
		if (r1 == l2) cout << r1 << " " << l2;
		else
			cout << max(l1, l2) << " " << min(r2, r1);
	}
	return 0;

}