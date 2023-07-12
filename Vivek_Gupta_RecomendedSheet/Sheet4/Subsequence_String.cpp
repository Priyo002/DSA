#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int l, count = 0, i;
	string s;
	cin >> s;
	l = s.size();
	for (i = 0 ; i < l ; i++)
	{
		if (s[i] == 'h' && count == 0)
			count = 1;
		else if (s[i] == 'e' && count == 1)
			count = 2;
		else if (s[i] == 'l' && count == 2)
			count = 3;
		else if (s[i] == 'l' && count == 3)
			count = 4;
		else if (s[i] == 'o' && count == 4)
			count = 5;
		if (count == 5)
			break;
	}
	if (count == 5)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;

}