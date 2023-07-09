#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif


	long long t, x;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x;
		long long ans = 1;

		if (x % 2 == 0)
			ans = ans * 2;
		while (x % 2 == 0)
			x = x / 2;
		for (int i = 3; i * i <= x; i = i + 2)
		{
			if (x % i == 0)
				ans = ans * i;
			while (x % i == 0)
				x = x / i;
		}
		if (x > 2)
			ans = ans * x;
		cout << ans << endl;
	}
	return 0;


}