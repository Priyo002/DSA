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
		string a, b;
		cin >> a >> b;
		string ans = "";
		int i;
		for (i = 0; i < min(a.size(), b.size()); i++) {
			ans += a[i];
			ans += b[i];
		}
		if (i == a.size()) {
			for (int j = i; j < b.size(); j++)
				ans += b[j];
		}
		else if (i == b.size()) {
			for (int j = i; j < a.size(); j++)
				ans += a[j];
		}
		cout << ans << endl;
	}

}