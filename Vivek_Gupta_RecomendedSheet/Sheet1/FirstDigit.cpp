#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int x;
	cin >> x;
	string str = to_string(x);
	int n = str[0] - '0';
	if ((n & 1) == 0) cout << "EVEN";
	else cout << "ODD";
}