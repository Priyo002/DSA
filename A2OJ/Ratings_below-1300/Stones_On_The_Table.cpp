#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			cnt++;
		}

	}
	cout << cnt ;
}