#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int k;
	cin >> k;
	string s, a;
	cin >> s;
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i += k) {
		if (s[i] == s[i + k - 1])
			a += s[i];
		else {
			cout << "-1";
			return 0;
		}
	}
	while (k--)
		cout << a;

}