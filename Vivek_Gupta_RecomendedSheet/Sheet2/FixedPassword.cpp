#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int x = 1999;
	while (true) {
		int n;
		cin >> n;
		if (n == x) {
			cout << "Correct";
			return 0;
		}
		else cout << "Wrong" << endl;
	}
}