#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	a--, x--, b--, y--;
	while (true) {
		if (a == b) {
			cout << "YES\n";
			return 0;
		}
		if (a == x || b == y) {
			break;
		}
		a = (a + 1) % n;
		b = (b - 1 + n) % n;
	}
	cout << "NO\n";
}