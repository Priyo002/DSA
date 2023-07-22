#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int x, n;
	cin >> x >> n;
	if (x == 0 || n == 0 || n == 1) {
		cout << 0;
		return 0;
	}
	long long sum = 0;
	long long p = 1;
	for (int i = 2; i <= n; i += 2) {
		sum += (p * x * x);
		p = sum;
	}
	cout << sum;

}