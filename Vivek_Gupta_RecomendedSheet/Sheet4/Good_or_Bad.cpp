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
		int lo = 0;
		int hi = 2;
		bool flag = false;
		while (hi < s.size()) {
			if (s[lo] == '0' && s[hi] == '0') {
				if (s[lo + 1] == '1') {
					flag = true;
					cout << "Good" << endl;
					break;
				}
			}
			else if (s[lo] == '1' && s[hi] == '1') {
				if (s[lo + 1] == '0') {
					flag = true;
					cout << "Good" << endl;
					break;
				}
			}
			lo++;
			hi++;
		}
		if (flag == false) cout << "Bad" << endl;
	}

}