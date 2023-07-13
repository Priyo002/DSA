#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b, k;
	cin >> a >> b >> k;
	if (a % k == 0 && b % k == 0) {
		cout << "Both";
	}
	else if (a % k == 0) {
		cout << "Memo";
	}
	else if (b % k == 0) {
		cout << "Momo";
	}
	else cout << "No One";

}