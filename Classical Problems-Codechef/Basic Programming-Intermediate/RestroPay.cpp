#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n, m, c;
	cin >> n >> m >> c;
	vector<long long> a(n);
	vector<long long> b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		long long temp = c - a[i];
		if (binary_search(b.begin(), b.end(), temp)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

}