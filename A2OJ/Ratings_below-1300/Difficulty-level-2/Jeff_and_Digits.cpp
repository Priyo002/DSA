#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int z = 0;
	int f = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 0) z++;
		else f++;
	}
	if (z == 0) {
		cout << -1;
	}
	else {
		if (f < 9) {
			cout << 0;
		}
		else if (f >= 9) {
			long long t = 0;
			if (f % 9 == 0) t = f;
			else {
				while (t + 9 <= f) {
					t += 9;
				}
			}
			string s = "";
			for (int i = 0; i < t; i++) {
				s.push_back('5');
			}
			for (int i = 0; i < z; i++)
				s.push_back('0');
			cout << s;
		}
	}
}