#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				flag = true;
				b[j] = -1;
				break;
			}
		}
		if (flag == false) {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
}