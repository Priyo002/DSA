#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	getline(cin, s);

	int i = 0;
	while (s[i] != '\\') {
		cout << s[i++];
	}

}