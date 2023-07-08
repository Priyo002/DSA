#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int T;
	long A, B, X, Y;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B >> X >> Y;
		if (Y >= X) {
			cout << 0 << endl;
		} else {
			long D = X - Y;
			long N = A / D + (A % D != 0);
			cout << ((B > Y * N) ? 1 : 0) << endl;
		}
	}
	return 0;
}