#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (isupper(s1[i])) s1[i] += 32;
		if (isupper(s2[i])) s2[i] += 32;
		char ch1 = s1[i];
		char ch2 =	s2[i];
		if (ch1 > ch2) {
			cout << 1;
			return 0;
		}
		else if (ch1 < ch2) {
			cout << -1;
			return 0;
		}
	}
	cout << 0;

}