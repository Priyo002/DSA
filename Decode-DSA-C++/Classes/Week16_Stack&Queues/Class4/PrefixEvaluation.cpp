#include<bits/stdc++.h>
using namespace std;

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

	string s = "-/*+79483";
	stack<int> val;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] >= 48 && s[i] <= 57) {
			val.push(s[i] - '0');
		}
		else {
			char ch = s[i];
			int val1 = val.top();
			val.pop();
			int val2 = val.top();
			val.pop();
			int ans = solve(val1, val2, ch);
			val.push(ans);
		}
	}
	cout << val.top();
}