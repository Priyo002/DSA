#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<long> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	vector<long> ans(v);
	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++) {
		cout << v[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << endl;
	}


}