#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	char ch;
	cin >> ch;
	if (islower(ch)) {
		cout << (char)(ch - 32);
	}
	else cout << (char)(ch + 32);

}