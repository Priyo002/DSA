#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			k = i + 1;
			break;
		}
	}
	for (int i = k; i < s.size(); i++) {
		if (s[i] == '=') {
			cout << ": ";
		}
		else if (s[i] == '&') {
			cout << endl;
		}
		else
			cout << s[i];
	}

}