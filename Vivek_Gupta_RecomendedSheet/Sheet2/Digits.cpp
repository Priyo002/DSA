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
		cout << n % 10;
		n /= 10;
		while (n) {
			cout << " " << n % 10;
			n /= 10;
		}
		cout << endl;
	}

}