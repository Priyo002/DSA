#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n;
	cin >> n;
	if (n == 1) {
		cout << "NO";
		return 0;
	}
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}