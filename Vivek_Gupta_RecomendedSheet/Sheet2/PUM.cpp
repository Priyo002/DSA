#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int p = 1;
	for (int i = 1; i <= n; i++) {
		int k = 3;
		while (k--) {
			cout << p++ << " ";
		}
		cout << "PUM" << endl;
		p++;
	}
}