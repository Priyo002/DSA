#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		double x, y, r;
		cin >> x >> y >> r;
		double extra = r / 30;
		double temp = x + extra;
		double k = temp / y;
		cout << ceil(k) << endl;
	}

}