#include<bits/stdc++.h>
using namespace std;

int sumof(int n) {
	if (n == 0) {
		return 0;
	}
	return n % 10 + sumof(n / 10);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int ans = sumof(n);
	cout << ans;
}