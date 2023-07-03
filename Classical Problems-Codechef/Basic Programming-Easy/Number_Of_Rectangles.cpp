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
		long long n, m;
		cin >> n >> m;
		long long sub_all = (n * (n + 1) / 2) * (m * (m + 1) / 2);
		long long subnm = n * m;
		cout << sub_all - subnm << endl;
	}
	return 0;

}