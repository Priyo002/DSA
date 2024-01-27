#include<bits/stdc++.h>
using namespace std;

bool power(int n) {
	if (n == 1) return true;
	else if (n % 2 != 0) return false;
	else if (n % 2 == 0) return power(n / 2);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	if (n % 2 != 0) cout << "false";
	else {
		if (power(n) == 0) cout << "false";
		else cout << "true";
	}

}