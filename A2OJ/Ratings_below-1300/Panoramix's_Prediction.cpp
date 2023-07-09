#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	while (true) {
		int temp = ++n;
		if (isPrime(temp)) {
			if (temp == m) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
			return 0;
		}
	}
}