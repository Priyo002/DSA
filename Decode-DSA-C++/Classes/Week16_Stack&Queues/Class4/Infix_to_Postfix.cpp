#include<bits/stdc++.h>
using namespace std;

int priority(char op) {
	if (op == '^') return 3;
	else if (op == '+' || op == '-') return 1;
	else return 2;
}
string solve(string val1, string val2, char ch) {
	string ans = "";
	ans += val1;
	ans += val2;
	ans.push_back(ch);
	return ans;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	stack<string> val;
	stack<char> op;

	string s = "(7+9)*4/8-3";

	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= 48 && s[i] <= 57) {
			val.push(to_string(s[i] - 48));
		}
		else {
			if (op.size() == 0) {
				op.push(s[i]);
			}
			else if (s[i] == '(') op.push(s[i]);
			else if (op.top() == '(') op.push(s[i]);
			else if (s[i] == ')') {
				while (op.top() != '(') {
					char ch = op.top();
					op.pop();
					string val2 = val.top();
					val.pop();
					string val1 = val.top();
					val.pop();
					string ans = solve(val1, val2, ch);
					val.push(ans);

				}
				op.pop();
			}
			else if (priority(op.top()) < priority(s[i])) op.push(s[i]);
			else {
				while (op.size() && priority(op.top()) >= priority(s[i])) {
					char ch = op.top();
					op.pop();
					string val2 = val.top();
					val.pop();
					string val1 = val.top();
					val.pop();
					string ans = solve(val1, val2, ch);
					val.push(ans);
				}
				op.push(s[i]);
			}
		}

	}

	while (op.size()) {
		char ch = op.top();
		op.pop();
		string val2 = val.top();
		val.pop();
		string val1 = val.top();
		val.pop();
		string ans = solve(val1, val2, ch);
		val.push(ans);
	}
	cout << val.top();

}