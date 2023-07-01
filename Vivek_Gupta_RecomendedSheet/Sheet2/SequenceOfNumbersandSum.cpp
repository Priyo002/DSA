#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n <= 0 || m <= 0) return 0;
		else {
			int sum = 0;
			if (n <= m) {
				for (int i = n; i <= m; i++) {
					sum += i;
					cout << i << " ";
				}
				cout << "sum =" << sum;
			}
			else {
				for (int i = m; i <= n; i++) {
					sum += i;
					cout << i << " ";
				}
				cout << "sum =" << sum;
			}
			cout << endl;
		}
	}

}