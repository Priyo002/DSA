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
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b >= 10) {
			cout << "YES";
		}
		else if (a + c >= 10) {
			cout << "YES";
		}
		else if (b + c >= 10) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;
	}

}