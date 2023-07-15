#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;

	string s = to_string(n);
	if (s[0] == '4') {
		cout << "NO";
		return 0;
	}

	while (n) {
		int rem = n % 10;
		if (rem != 1 && rem != 4) {
			cout << "NO";
			return 0;
		}
		n /= 10;
	}
	int f = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == '4') f++;
	}
	if (f > 2) {
		cout << "NO";
		return 0;
	}
	int lo = 1;
	int hi = 3;
	while (hi < s.size()) {
		if (s[lo - 1] == '4') f--;
		if (s[hi] == '4') f++;
		lo++;
		hi++;
		if (f > 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


}