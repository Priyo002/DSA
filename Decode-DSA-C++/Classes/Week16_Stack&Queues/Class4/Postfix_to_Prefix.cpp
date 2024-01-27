#include<bits/stdc++.h>
using namespace std;

string solve(string val1, string val2, char ch) {

	string ans = "";

	ans.push_back(ch);
	ans += val1;
	ans += val2;

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s = "79+4*8/3-";
	stack<string> val;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			val.push(to_string(s[i] - '0'));
		}
		else {
			char ch = s[i];
			string val2 = val.top();
			val.pop();
			string val1 = val.top();
			val.pop();
			string ans = solve(val1, val2, ch);
			val.push(ans);
		}
	}
	cout << val.top();
}