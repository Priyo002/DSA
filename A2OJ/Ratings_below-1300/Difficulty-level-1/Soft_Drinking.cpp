#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np ;
	int toasts = (k * l) / nl;
	int limes = c * d;
	int salts = p / np;
	int mini = min(toasts, limes);
	cout << min(mini, salts) / n;
}
