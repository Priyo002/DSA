#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n;
	cin >> n;
	long long k = __builtin_popcount(n);
	if (k == 1) {
		cout << "YES";
	}
	else cout << "NO";

}