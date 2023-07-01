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
		int n;
		cin >> n;
		int k = __builtin_popcount(n);
		long sum = 0;
		int i = 0;
		while (k--) {
			sum += pow(2, i);
			i++;
		}
		cout << sum << endl;


	}
}