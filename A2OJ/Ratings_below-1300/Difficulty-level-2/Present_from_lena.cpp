#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, i, j, k;
	cin >> n;
	for (j = 0; j <= 2 * n; j++) {
		i = n - abs(j - n);
		k = 0;
		while (k < n - i) {
			cout << "  ";
			k++;
		}
		k = i;
		while (k > -i) {
			cout << i - abs(k) << " ";
			k--;
		}
		cout << 0 << endl;
	}
	return 0;

}