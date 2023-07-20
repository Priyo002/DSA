#include<bits/stdc++.h>
using namespace std;

double help(double x, double lo, double hi) {
	double ans = 0;
	for (double i = lo; i <= hi; i += 2) {
		ans += pow(x, i);
	}
	ans = (long long)ans;
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	double x, n;
	cin >> x >> n;
	if (x == 0) {
		cout << 0;
		return 0;
	}
	if (n == 0 || n == 1) {
		cout << 0;
		return 0;
	}
	cout << help(x, 2, n);
}