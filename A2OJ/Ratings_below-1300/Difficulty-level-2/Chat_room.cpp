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
		if (str.size() == 0 && s[i] == 'h') {
			str.push_back(s[i]);
		}
		else if (str.size() == 1 && s[i] == 'e') {
			str.push_back(s[i]);
		}
		else if (str.size() >= 2 && str.size() <= 3 && s[i] == 'l') {
			str.push_back(s[i]);
		}
		else if (str.size() == 4 && s[i] == 'o') {
			str.push_back(s[i]);
		}
	}
	if (str == "hello") cout << "YES";
	else cout << "NO";

}