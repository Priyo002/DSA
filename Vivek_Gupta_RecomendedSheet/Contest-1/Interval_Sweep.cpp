#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;

	if (a == 0 && b == 0) cout << "NO";
	else if (abs(a - b) > 1) cout << "NO";
	else cout << "YES";

}