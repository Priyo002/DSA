#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string x, y;
	cin >> x >> y;

	int n = x.size();
	int m = y.size();
	int i = 0;
	while (i < n && i < m) {
		if (x[i] == y[i])
			i++;
		else {
			if (x[i] > y[i])
				cout << y;
			else
				cout << x;
			return 0;
		}
	}
	if (x.size() == y.size())
		cout << x;
	else {
		if (i == n) cout << x;
		else cout << y;
	}
}