#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, i, count = 1;
	cin >> n;
	string s;
	cin >> s;
	for (i = 0 ; i < n - 1 ; i++)
	{
		if (s[i] != s[i + 1])
			count++;
	}
	cout << count << endl;
	return 0;

}