#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	char ch;
	cin >> a >> ch >> b;
	if (ch == '<') {
		if (a < b) cout << "Right";
		else cout << "Wrong";
	}
	else if (ch == '>') {
		if (a > b) cout << "Right";
		else cout << "Wrong";
	}
	else {
		if (a == b) cout << "Right";
		else cout << "Wrong";
	}

}