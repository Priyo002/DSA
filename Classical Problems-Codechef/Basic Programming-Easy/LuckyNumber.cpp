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
		long long n;
		cin >> n;
		int i = 0;
		while (n % 2 == 0) {
			n /= 2;
			i++;
		}
		if (i % 2 == 0) cout << 1 << endl;
		else cout << 0 << endl;

	}

}