#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	int n;
	cin >> n;
	if (n > s.size()) {
		cout << "impossible";
		return 0;
	}
	unordered_set<char> st;
	for (int i = 0; i < s.size(); i++) {
		st.insert(s[i]);
	}
	if (st.size() > n) {
		cout << 0;
	}
	else
		cout << n - st.size();

}