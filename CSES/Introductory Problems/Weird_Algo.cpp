#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long int n;
	cin >> n;
	cout << n;
	while (n > 1) {

		if (n % 2 == 0) {
			n /= 2;
		}
		else n = n * 3 + 1;
		cout << " " << n;

	}

	return 0;
}