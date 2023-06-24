#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n == 1) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if ((i & 1) == 0) cout << i << endl;
	}
}