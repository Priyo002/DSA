#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
	if (b == 0 || a == 0) return 1;
	return a * power(a, b - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	cout << power(a, b);
}