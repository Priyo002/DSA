#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int i, t;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		long long int a, b, c, d;
		long double f = 0, e, g;
		cin >> a >> b >> c >> d;
		if (a >= b)
			cout << 0 << endl;
		else if (c == 1 && d == 1)
			cout << -1 << endl;
		else
		{
			e = a;
			g = b;
			while (e <= b && g > a)
			{
				e = e * c;
				g = floor(g / d);
				f++;
			}
			cout << f << endl;
		}
	}
	// your code goes here
	return 0;

}