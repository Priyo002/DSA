#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int X, M;
		cin >> X >> M;
		long int Y = 0;
		int power = M % 4;
		if (power == 0 and M != 0)
			power = 4;
		while (X) {
			int digit = pow(X % 10, power);
			digit = digit % 10;
			Y = Y * 10 + digit;
			X = X / 10;
		}
		if (Y % 7 == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}