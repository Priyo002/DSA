#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str;
	cin >> str;
	if (str.size() % 2 != 0) {
		cout << "Not Balanced";
		return 0;
	}
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (s.top() == '(')
				s.pop();
			else {
				cout << "Not Balanced";
				return 0;
			}
		}
	}
	if (s.size() == 0) {
		cout << "Yes Balanced";
	}
	else cout << "Not Balanced";

}