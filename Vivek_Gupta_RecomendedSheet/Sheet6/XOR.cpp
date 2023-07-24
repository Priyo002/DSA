#include<bits/stdc++.h>
using namespace std;

long long help(long long a, long long b, long long q) {
	if (q == 1) {
		return a;
	}
	else if (q == 2) return b;
	return help(a, b, q - 1)^help(a, b, q - 2);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b, q;
	cin >> a >> b >> q;
	long long ans = help(a, b, q);
	cout << ans;


}