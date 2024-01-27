#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
	stack<char> st;
	st.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != st.top()) st.push(s[i]);
	}
	string ans;
	while (st.size()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s = "aaabbcddaafffg";
	cout << s << endl;
	s = removeDuplicates(s);
	cout << s;

}