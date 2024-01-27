#include<bits/stdc++.h>
using namespace std;

int prod(int a, int b) {
	if (b == 0) return 1;
	return a * prod(a, b - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	cout << prod(a, b);
}