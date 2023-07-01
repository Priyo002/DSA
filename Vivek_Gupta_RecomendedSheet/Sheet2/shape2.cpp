#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i + 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
}