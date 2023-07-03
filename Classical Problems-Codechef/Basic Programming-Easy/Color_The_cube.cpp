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
		long long n, a, b, c, d, e, f;
		cin >> n >> a >> b >> c >> d >> e >> f;
		long long l = ceil(n * 0.5);
		long long ans = (a + b + c + d + e + f) * l;
		cout << ans << endl;
	}

}