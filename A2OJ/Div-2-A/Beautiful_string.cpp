#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool flag = false;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == '?') continue;
			if (s[i] == s[i + 1]) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			cout << -1 << endl;
			continue;
		}
		if (s.size() == 1) {
			if (s[0] == '?') {
				cout << 'a' << endl;
				continue;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') {
				if (i == 0) {
					if (s[i + 1] == '?') s[i] = 'a';
					else {
						if (s[i + 1] == 'a') {
							s[i] = 'b';
						}
						else {
							s[i] = (char)(s[i + 1] - 1);
						}
					}
				}
				else if (i == s.size() - 1) {
					if (s[i - 1] == 'c') {
						s[i] = 'a';
					}
					else s[i] = (char)(s[i - 1] + 1);
				}
				else {
					if (s[i + 1] == '?') {
						if (s[i - 1] == 'a') {
							s[i] = 'b';
						}
						else s[i] = (char)(s[i - 1] - 1);
					}
					else {
						if (s[i + 1] == 'b' && s[i - 1] == 'a') {
							s[i] = 'c';
						}
						else if (s[i + 1] == 'a' && s[i - 1] == 'b') {
							s[i] = 'c';
						}
						else if (s[i + 1] == 'b' && s[i - 1] == 'c') {
							s[i] = 'a';
						}
						else if (s[i + 1] == 'c' && s[i - 1] == 'b') {
							s[i] = 'a';
						}
						else if (s[i + 1] == 'a' && s[i - 1] == 'c') {
							s[i] = 'b';
						}
						else if (s[i + 1] == 'c' && s[i - 1] == 'a') {
							s[i] = 'b';
						}
						else if (s[i + 1] == 'c' && s[i - 1] == 'c') {
							s[i] = 'b';
						}
						else if (s[i + 1] == 'a' && s[i - 1] == 'a') {
							s[i] = 'b';
						}
						else if (s[i + 1] == 'b' && s[i - 1] == 'b') {
							s[i] = 'a';
						}
					}
				}
			}
		}
		cout << s << endl;
	}

}