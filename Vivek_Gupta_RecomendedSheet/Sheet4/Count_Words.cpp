#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	getline(cin, s);
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isalnum(s[i])) {
			while (isalnum(s[i])) {
				i++;
			}
			cnt++;
		}
	}
	cout << cnt;
}