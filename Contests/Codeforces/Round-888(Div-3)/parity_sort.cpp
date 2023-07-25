#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (b[i] % 2 == 0) {
				if (a[i] % 2 != 0) {
					cout << "NO";
					flag = false;
					break;
				}
			}
			else if (b[i] % 2 != 0) {
				if (a[i] % 2 == 0) {
					cout << "NO";
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			cout << "YES";
		}
		cout << endl;
	}

}