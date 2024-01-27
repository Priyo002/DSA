#include<bits/stdc++.h>
using namespace std;

void printFactors(int n) {
	for (int i = 1; i < sqrt(n); i++) {
		if (n % i == 0) {
			cout << i << " " ;
		}
	}
	for (int i = sqrt(n); i >= 1; i--) {
		if (n % i == 0) {
			cout << n / i << " " ;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	printFactors(n);


}