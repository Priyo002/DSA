#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	int lo = 0;
	int hi = s.size() - 1;
	while (lo < hi) {
		if (s[lo] != s[hi]) {
			cout << "NO";
			return 0;
		}
		lo++;
		hi--;
	}
	cout << "YES";

}