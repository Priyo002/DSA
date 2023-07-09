#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') s[i] = ' ';
		else if (islower(s[i])) s[i] -= 32;
		else s[i] += 32;
	}
	cout << s;

}