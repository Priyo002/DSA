#include<bits/stdc++.h>
using namespace std;

int priority(char op) {
	if (op == '^') return 3;
	else if (op == '+' || op == '-') return 1;
	else return 2;
}

int solve(int val1, int val2, char ch) {
	int ans = 0;
	switch (ch) {
	case '+' :
		ans = val1 + val2;
		break;
	case '*' :
		ans = val1 * val2;
		break;
	case '/' :
		ans = val1 / val2;
		break;
	case '-' :
		ans = val1 - val2;
		break;
	case '^' :
		ans = pow(val1, val2);
		break;
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	stack<int> val;
	stack<char> op;

	string s = "(5+3)-8+3*4";

	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= 48 && s[i] <= 57) {
			val.push(s[i] - '0');
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
					int val2 = val.top();
					val.pop();
					int val1 = val.top();
					val.pop();
					int ans = solve(val1, val2, ch);
					val.push(ans);

				}
				op.pop();
			}
			else if (priority(op.top()) < priority(s[i])) op.push(s[i]);
			else {
				while (op.size() && priority(op.top()) >= priority(s[i])) {
					char ch = op.top();
					op.pop();
					int val2 = val.top();
					val.pop();
					int val1 = val.top();
					val.pop();
					int ans = solve(val1, val2, ch);
					val.push(ans);
				}
				op.push(s[i]);
			}
		}

	}

	while (op.size()) {
		char ch = op.top();
		op.pop();
		int val2 = val.top();
		val.pop();
		int val1 = val.top();
		val.pop();
		int ans = solve(val1, val2, ch);
		val.push(ans);
	}
	cout << val.top();
}