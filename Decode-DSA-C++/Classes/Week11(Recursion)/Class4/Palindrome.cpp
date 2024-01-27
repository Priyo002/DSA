#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int i, int j) {
	if (s[i] != s[j]) return false;
	if (i > j) return true;
	return palindrome(s, i + 1, j - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	string s;
	getline(cin, s);
	cout << palindrome(s, 0, s.size() - 1);

}