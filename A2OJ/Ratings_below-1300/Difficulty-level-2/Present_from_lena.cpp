#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int a = n;
	for (int i = 0; i < n; i++) {
		for (int s = 0; s < a; s++) {
			cout << " ";
		}
		a--;
		int k;
		for (int j = 0; j <= i; j++) {
			cout << j << " ";
			k = j;
		}
		for (int l = k - 1; l >= 0; l--) {
			cout << l << " ";
		}
		cout << endl;
	}
	cout << 0 << " ";
	int t;
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
		t = i;
	}
	for (int m = t - 1; m >= 0; m--) {
		cout << m << " ";
	}
	cout << endl;

}