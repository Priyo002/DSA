#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str;
	cin >> str;
	string s = "";
	int i;
	for (i = 0; i < str.size() - 1; i++) {
		if (str[i] == '-' && str[i + 1] == '.') {
			s += "1";
			i++;
		}
		else if (str[i] == '-' && str[i + 1] == '-') {
			s += "2";
			i++;
		}
		else {
			s += "0";
		}
	}
	if (i < str.size()) {
		if (str[str.size() - 1] == '.') {
			s += "0";
		}
	}
	cout << s;

}