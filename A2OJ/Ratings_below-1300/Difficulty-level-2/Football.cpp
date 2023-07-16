#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<string> v;
	string s;
	cin >> s;
	v.push_back(s);
	int cnt1 = 1;
	int cnt2 = 0;
	for (int i = 1; i < n; i++) {
		string str;
		cin >> str;
		if (str == v[0]) cnt1++;
		else {
			if (v.size() == 1)
				v.push_back(str);
			cnt2++;
		}
	}
	if (v.size() == 1) {
		cout << v[0];
		return 0;
	}
	if (cnt1 > cnt2) cout << v[0];
	else cout << v[1];

}