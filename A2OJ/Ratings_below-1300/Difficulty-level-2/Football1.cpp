#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	if (s.size() < 7) {
		cout << "NO";
		return 0;
	}
	string ans = "1111111";
	string ans1 = "0000000";

	int i = 1;
	string str = "";
	str.push_back(s[0]);
	while (i < s.size()) {
		if (str[0] == s[i]) {
			str.push_back(s[i]);
		}
		else {
			str = "";
			str.push_back(s[i]);
		}
		if (str.size() == 7) {
			cout << "YES";
			return 0;
		}
		i++;
	}
	cout << "NO";

}