#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	int x = 0;
	while (t--) {
		string s;
		cin >> s;
		if (s[1] == '+') x++;
		else x--;
	}

	cout << x;
}