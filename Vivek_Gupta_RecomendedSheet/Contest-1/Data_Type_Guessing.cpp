#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n, k, a;
	cin >> n >> k >> a;
	if ((n * k) % a != 0) {
		cout << "double";
		return 0;
	}
	long long ans = (n * k) / a;
	if (ans >= -2147483648 && ans <= 2147483647) {
		cout << "int";
	}
	else cout << "long long";
}