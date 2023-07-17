#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int a, b;
	a = n % 10;
	b = n / 10;

	if (a % b == 0 || b % a == 0) {
		cout << "YES";
	}
	else cout << "NO";

}