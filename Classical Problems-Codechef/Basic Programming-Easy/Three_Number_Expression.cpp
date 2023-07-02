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
		long long a, b, c;
		cin >> a >> b >> c;
		if (a - b - c == 0) {
			cout << "YES" << endl;
			continue;
		}
		if (a - b + c == 0 || a + b - c == 0) {
			cout << "YES" << endl;
			continue;
		}
		if (b - a - c == 0 || b - a + c == 0 || c - a - b == 0) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}

}