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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "NO";
			cout << endl;
			continue;
		}
		if (isPrime(n)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}

}