#include<bits/stdc++.h>
using namespace std; \

bool isVowel(char ch) {
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y')
		return true;
	else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
		return true;
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	string str = "";
	for (int i = 0; i < s.size(); i++) {
		if (!isVowel(s[i])) {
			str.push_back('.');
			if (isupper(s[i])) s[i] = s[i] + 32;
			str.push_back(s[i]);
		}
	}
	cout << str;

}