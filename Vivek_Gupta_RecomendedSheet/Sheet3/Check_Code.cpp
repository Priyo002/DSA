#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == a) {
			if (s[i] == '-') {
				continue;
			}
			else {
				cout << "No";
				return 0;
			}
		}
		else {
			if (s[i] == '-') {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}