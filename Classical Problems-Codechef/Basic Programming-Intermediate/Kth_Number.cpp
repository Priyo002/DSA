#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int l, m, h;

		if (n % 3 == 1)
		{
			l = n / 3 + 1;
			m = n / 3;
			h = n / 3;
		}

		else if (n % 3 == 2)
		{
			l = n / 3 + 1;
			m = n / 3 + 1;
			h = n / 3;
		}

		else
		{
			l = n / 3;
			m = n / 3;
			h = n / 3;
		}



		if (k <= l)
		{
			cout << (k - 1) * 3 + 1 << endl;
		}

		else if (k <= (m + l))
		{
			cout << (k - l - 1) * 3 + 2 << endl;
		}
		else
		{
			cout << (k - l - m) * 3 << endl;
		}
	}
	return 0;
}