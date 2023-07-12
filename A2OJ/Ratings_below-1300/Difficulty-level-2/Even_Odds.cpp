#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n, k, t;
	cin >> n >> k;
	if (n % 2 == 0) {
		t = n / 2;
	}
	else t = n / 2 + 1;
	long long cnt = 0;
	if (k <= t) {
		cout << 2 * k - 1;
	}
	else {
		k = k - t;
		cout << 2 * k;
	}

}