#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	string str = "";
	for (int i = 0; i < s.size(); i++) {
		if (i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			i += 2;
			if (str.size()) str.push_back(' ');
		}
		else str.push_back(s[i]);
	}
	cout << str;

}