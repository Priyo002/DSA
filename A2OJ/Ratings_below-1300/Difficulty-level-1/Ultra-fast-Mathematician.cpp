#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	string s1, s2, ans;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) ans += "0";
		else ans += "1";
	}
	cout << ans;

}