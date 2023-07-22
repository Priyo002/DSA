#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int s, n;
	cin >> s >> n;
	multimap<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mp.insert(make_pair(a, b));
	}
	for (auto it : mp) {
		if (it.first < s) {
			s += it.second;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}