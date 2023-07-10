#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9' ) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}