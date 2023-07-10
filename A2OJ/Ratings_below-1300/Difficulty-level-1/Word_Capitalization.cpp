#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	if (isupper(s[0])) cout << s;
	else {
		s[0] = s[0] - 32;
		cout << s;
	}

}