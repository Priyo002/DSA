#include<bits/stdc++.h>
using namespace std;

bool unique(int n) {
	vector<int> v(10, 0);
	while (n) {
		int rem = n % 10;
		v[rem]++;
		if (v[rem] > 1) return false;
		n /= 10;
	}
	return true;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		while (true) {
			int y = ++x;
			if (unique(y)) {
				cout << y << endl;
				break;
			}
		}
	}
}