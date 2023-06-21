#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	if (a % b == 0 || b % a == 0) cout << "Multiples";
	else cout << "No Multiples";
}