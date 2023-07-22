#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> v(n, 0);
	int j = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			v[j++] = a;
		}
	}
	for (auto it : v) cout << it << " ";
}