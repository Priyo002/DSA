#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
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

	int n;
	cin >> n;
	cout << 2;
	for (int i = 3; i <= n; i++) {
		if (isPrime(i)) cout << " " << i;
	}

}

