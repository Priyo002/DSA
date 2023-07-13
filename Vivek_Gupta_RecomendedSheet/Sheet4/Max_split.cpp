#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	int l, i, R = 0, L = 0, count = 0;
	l = s.size();
	for (i = 0 ; i < l ; i++)
	{
		if (s[i] == 'L')
		{
			L++;
		}
		else
		{
			R++;
		}
		if (L == R)
		{
			count++;
			L = 0;
			R = 0;
		}
	}
	cout << count << endl;
	for (i = 0 ; i < l ; i++)
	{
		if (s[i] == 'L')
		{
			L++;
			cout << s[i];
		}
		else
		{
			R++;
			cout << s[i];
		}
		if (L == R)
		{
			L = 0;
			R = 0;
			cout << endl;
		}
	}
	return 0;


}