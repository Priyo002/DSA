#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s, t;
	cin >> s >> t;
	if (s.size() != t.size()) {
		cout << "NO";
		return 0;
	}
	int n = s.size();
	int i = n - 1;
	int j = 0;
	while (i >= 0 && j < n) {
		if (s[i] != t[j]) {
			cout << "NO";
			return 0;
		}
		i--;
		j++;
	}
	cout << "YES";

}