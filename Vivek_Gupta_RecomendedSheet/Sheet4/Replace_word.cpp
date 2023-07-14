#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	getline(cin, s);

	string ans = "EGYPT";
	string str = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'E') {
			str.push_back(s[i]);
		}
		else {
			string temp = "";
			for (int j = i; j < i + 5; j++) {
				temp.push_back(s[j]);
			}
			if (temp == ans) {
				str.push_back(' ');
				i += 4;
			}
			else {
				str.push_back(s[i]);
			}
		}
	}
	cout << str;

}