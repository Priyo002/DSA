#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	long long int ttc;
	cin >> ttc;
	while (ttc--)
	{
		long long int n, zero, i, c;
		string s;
		zero = c = 0;
		cin >> s;
		n = s.size();
		for (i = 0; i < n; i++)
		{
			if (s[i] == '0')
				zero++;
			if (zero == 2 && s[i] == '7')
				c++;
			if (zero > 2 && s[i] == '7')
				c = c + (zero * (zero - 1)) / 2;
		}
		cout << c << endl;
	}
	return 0;

}